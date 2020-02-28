<?php
	
	$con = mysqli_connect('localhost', 'root','root','naavi_pge');
	//verifier connection
	if (mysqli_connect_errno())
	{
		echo "1: Connection failed";//error 1 ==  conection failed
		exit();
	}

	$usernom = $_POST["nom"];
	$userprenom = $_POST["prenom"];
	$identification = $_POST["identification"];
	$password = $_POST["password"];
	//check if identification name exist
	$namecheckquery = "SELECT identification FROM users WHERE identification='".$identification."';";
	$namecheck = mysqli_query($con,$namecheckquery) or die("2: Name query failed");
	
	if (mysqli_num_rows($namecheck)>0){

		echo"3: Name already exists";
		exit();
	}

	//add user to the table

	$salt = "\$5\$rounds=5000\$"."youShallNotPass".$usernom."\$";
	$hash = crypt($password,$salt);
	$insertuserquery = "INSERT INTO users (identification, nom, prenom, hash,salt) VALUES ('". $identification ."','". $usernom ."','". $userprenom ."','" . $hash . "','" . $salt . "');";
	mysqli_query($con, $insertuserquery) or die("4: insert user query failed");// error 4 == probleme insertion users
	echo"0";





?>