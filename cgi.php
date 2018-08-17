<?php 
$hex = $_GET['q'];
$output=shell_exec("sudo ./Decoder ".substr($hex, 2));
$br_added_output=str_replace("\n", "<br>", $output);
echo $br_added_output;
 ?>

