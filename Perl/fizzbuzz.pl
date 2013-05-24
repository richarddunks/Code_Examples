#!/usr/bin/perl
use strict;
use warnings;

for (my $count = 1; $count <= 100; $count++) {
	if ($count%15 == 0) 
	{
		print "FIZZBUZZ\n";
	} 
	elsif ($count%3 == 0) 
	{
		print "FIZZ\n";
	} 
	elsif ($count%5 == 0) 
	{
		print "BUZZ\n";
	} 
	else 
	{
		print "$count\n";
	}

}