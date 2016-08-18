#!/usr/bin/perl
use List::Util qw(max);

my $dataset_size = 100;
my $random_max = 100;
my $k = 0;
my $total = 0;
my $idx = 0;

my @aaa = (0) x $dataset_size;
my @bbb = (0) x $dataset_size;
my @ccc = ();

for($idx=0;$idx<$dataset_size;$idx++){
	$aaa[$idx] = int(rand($random_max));
	print $aaa[$idx],"\n";
}

$k = max(@aaa);
@ccc = (0) x ($k+1);
for my $idx (@aaa) {
	$ccc[$idx] += 1;
}
print @ccc,"\n";
$total = 0;
for($idx=0; $idx<=$k; $idx++){
	$total += $ccc[$idx];
	$ccc[$idx] = $total;
}
print @ccc,"\n";
for $idx (reverse(@aaa)) {
	$bbb[$ccc[$idx]] = $idx;
	$ccc[$idx] -= 1;
}

for($idx=0;$idx<$dataset_size;$idx++){
	print $bbb[$idx],"\n";
}
