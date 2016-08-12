<?php

define("DATASET_SIZE", 100);

$lower = 0;
$upper = 100;
$k = 0;
$aaa;
$bbb;
$ccc;
$idx;
$total;

$random_number = mt_rand($lower,$upper);
for( $idx=0; $idx<DATASET_SIZE; $idx++){
	$aaa[$idx] = mt_rand($lower,$upper);
	$bbb[$idx] = 0;
}
print("the start of array aaa.\n");
var_dump( $aaa );
print("the end of array aaa.\n\n\n");

$k = max($aaa);
for( $idx=0; $idx<=$k; $idx++ ){
	$ccc[$idx] = 0;
}
for( $idx=0; $idx<DATASET_SIZE; $idx++){
	$ccc[$aaa[$idx]] += 1;
}
$total=0;
for( $idx=0; $idx<=$k; $idx++ ){
	$total += $ccc[$idx];
	$ccc[$idx] = $total;
}

print("the start of array ccc.\n");
var_dump( $ccc );
print("the end of array ccc.\n\n\n");

for( $idx=DATASET_SIZE-1; $idx>=0; $idx--){
	$bbb[$ccc[$aaa[$idx]]] = $aaa[$idx];
	$ccc[$aaa[$idx]] -= 1;
}
print("the start of array bbb.\n");
var_dump( $bbb );
print("the end of array bbb.\n\n\n");
?>
