#!/usr/bin/perl
use strict;
use warnings;

for (my $i = 0; $i < 5000000; $i++) {
	print int(rand(16777216))."\n";
}
