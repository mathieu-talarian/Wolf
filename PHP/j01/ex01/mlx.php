#!/usr/bin/php
<?PHP
$var = 0;
while (++$var < 1001)
{
	echo ("X");
	if (($var% 98) == 0)
		echo ("\n");
}
echo "\n";
?>
