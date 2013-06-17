#!/usr/bin/perl

#Script to append a filename column to the data
#Script takes in three arguments <infile>, <outfile>, and <columnVal> from the
#UNIX command line when the file is called
#<infile> is the input file
#<outfile> is the desired output file
#<columnVal> is the value for the additional column

use strict;
use warnings;
use FileHandle;

my $infile = shift; #gets first argument in ARGV array
my $outfile = shift;
my $columnVal = shift; 

#assign file handles
open INPUTFILE, "<", $infile or die $!;
open OUTPUTFILE, ">", $outfile or die $!;

#while loop to process and output file
while (<INPUTFILE>)
{
	#getline
	my $line = $_;

	#remove newline character
	chomp($line);

	#join file name to each line of text
	my $result = $line.",$columnVal\n";

	#write result to file
	print OUTPUTFILE $result or die $!;
} #end while


close OUTPUTFILE or die $!;
close INPUTFILE or die $!;
