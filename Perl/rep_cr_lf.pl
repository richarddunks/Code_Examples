#!/usr/bin/perl

#Script to convert carriage return (^M or 0d in hex) to line feed (\n or 0a in hex)
#Script takes in two arguments <infile> and <outfile> from the
#UNIX command line when the file is called
#<infile> is the input file
#<outfile> is the desired output file

use strict;
use warnings;

my $infile = shift; #gets first argument in ARGV array
my $outfile = shift;

#assign file handles
open INPUTFILE, "<", $infile or die $!;
open OUTPUTFILE, ">", $outfile or die $!;

while (<INPUTFILE>)
{
	#getline
	my $line = $_;

	#replace carriage return with line feed
	$line =~ tr/\r/\n/;

	#write result to file
	print OUTPUTFILE $line or die $!;

} #end while

close OUTPUTFILE or die $!;
close INPUTFILE or die $!;
