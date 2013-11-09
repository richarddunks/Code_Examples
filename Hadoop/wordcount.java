import java.io.IOException;
import java.util.*;

import org.apache.hadoop.fs.Path;
import org.apache.hadoop.conf.*;
import org.apache.hadoop.io.*;
import org.apache.hadoop.mapred.*;
import org.apache.hadoop.util.*;
	
public class WordCount extends Configured implements Tool {

  public static class Map extends MapReduceBase implements Mapper<LongWritable, Text, Text, IntWritable> {
    
    private final static IntWritable one = new IntWritable(1); //set the default value
    private Text word = new Text(); //container for word token

    //set for the -word-length flag
    private boolean wordLengthComp = false; //default off for word length comparison
    private int wordLength = 0; //default value for word length

    //set for the -prefix flag
    private boolean prefixComp = false;
    private String prefixValue = "";
    private int prefixLength = 0;

    public void configure(JobConf job){ //configure based on settings in conf object

      //boolean flag to set the wordlength comparison
      wordLengthComp = job.getBoolean("wordlength.calc",false); 

      //test for wordlength boolean being true and, if true, assign length value
      if (wordLengthComp) {
        wordLength = job.getInt("wordlength.value",0);
      }

      //boolean flag for use of -prefix option
      prefixComp = job.getBoolean("prefix.search",false);

      //test for prefix boolean being true and, if true, set prefix to String value
      if (prefixComp) {
        prefixValue = job.get("prefix.value","");
        prefixLength = prefixValue.length();
      }

    }

    public void map(LongWritable key, Text value, OutputCollector<Text, IntWritable> output, Reporter reporter) throws IOException {

      //get line of input to evaluate
      String line = value.toString();

      //cast line into StringTokenizer object
      StringTokenizer tokenizer = new StringTokenizer(line);

      while (tokenizer.hasMoreTokens()) { //iterate through tokens
        
        //set word object = token in tokenizer
        word.set(tokenizer.nextToken()); 
        
        //cast word to String for comparison operations
        String wordString = word.toString(); 
        
        //set of checks to emit (K,V) only if it meets logical conditions
        if ( wordLengthComp && wordString.length() == wordLength ){

          //emit K,V if -wordlength set and length matches user-defined length
          output.collect(new Text(wordString), one); 

        } else if ( prefixComp && wordString.length() >= prefixLength && prefixValue.equals(wordString.substring(0, prefixLength)) ) {
          
          //emit K,V if -prefix set and word prefix matches prefix
          output.collect(new Text(wordString), one); 
        
        } else if (!wordLengthComp && !prefixComp) {
          
          //emit all K,V (default behavior)
          output.collect(new Text(wordString), one); 

        }
      }
    }
  }

  public static class Reduce extends MapReduceBase implements Reducer<Text, IntWritable, Text, IntWritable> {
      public void reduce(Text key, Iterator<IntWritable> values, OutputCollector<Text, IntWritable> output, Reporter reporter) throws IOException {
        int sum = 0;
        while (values.hasNext()) {
          sum += values.next().get();
        }
        output.collect(key, new IntWritable(sum));
      }
    }

  public int run(String[] args) throws Exception {    
    JobConf conf = new JobConf(WordCount.class);
    conf.setJobName("wordcount");

    conf.setOutputKeyClass(Text.class);
    conf.setOutputValueClass(IntWritable.class);

    conf.setMapperClass(Map.class);
    conf.setReducerClass(Reduce.class);

    conf.setInputFormat(TextInputFormat.class);
    conf.setOutputFormat(TextOutputFormat.class);

    List<String> other_args = new ArrayList<String>();
    for (int i=0; i < args.length; ++i) {
      if ("-combiner".equals(args[i])) {
        conf.setCombinerClass(Reduce.class);
      } else if ("-word-length".equals(args[i])) {
        conf.setBoolean("wordlength.calc", true); //set boolean flag
        conf.setInt("wordlength.value", Integer.parseInt(args[++i])); //set  integer value
      } else if ("-prefix".equals(args[i])) {
        conf.setBoolean("prefix.search", true); //set boolean flag
        conf.set("prefix.value", args[++i]); //set prefix value
      } else {
        other_args.add(args[i]);
      }
    }
    FileInputFormat.setInputPaths(conf, new Path(args[0]));
    FileOutputFormat.setOutputPath(conf, new Path(args[1]));

    JobClient.runJob(conf);
    return 0;
  }

  p
    int res = ToolRunner.run(new Configuration(), new WordCount(), args); //
    System.exit(res);
  }
}

