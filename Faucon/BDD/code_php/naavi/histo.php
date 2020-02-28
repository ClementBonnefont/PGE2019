<?php
	$con = mysqli_connect('localhost', 'root','root','naavi_pge');
	//verifier connection
	if (mysqli_connect_errno())
	{
		echo "1: Connection failed";//error 1 ==  conection failed
		exit();
	}

	$namecheckquery = "SELECT * from mission;";
	$namecheck = mysqli_query($con,$namecheckquery) or die("2: Name query failed");

	$num = mysqli_num_rows ($namecheck);
	echo "$num";
	
	while ($existinginfo = mysqli_fetch_array($namecheck,MYSQLI_NUM)){
		echo ",".$existinginfo[0].",". $existinginfo[1].",". $existinginfo[2].",". $existinginfo[3].",". $existinginfo[4].",". $existinginfo[5].",". $existinginfo[6].",". $existinginfo[7].",". $existinginfo[8].",". $existinginfo[9].",". $existinginfo[10].",". $existinginfo[11].",". $existinginfo[12].",". $existinginfo[13].",". $existinginfo[14];

	}
	
	


	
?>