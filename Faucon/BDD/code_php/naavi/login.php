<?php

	$con = mysqli_connect('localhost', 'root','root','naavi_pge');
	//verifier connection
	if (mysqli_connect_errno())
	{
		echo "1: Connection failed";//error 1 ==  conection failed
		exit();
	}

	$usernom = $_POST["identification"];
	$password = $_POST["password"];


	//check if name exists
	$namecheckquery = "SELECT identification,nom,prenom,salt, hash FROM users WHERE identification ='".$usernom."';";
	$namecheck = mysqli_query($con,$namecheckquery) or die("2: Name check query failed");

	if (mysqli_num_rows($namecheck) != 1){
		echo " 5: Either no user with name or more than one";
		exit();
	}
	//get login info from query
	$existinginfo = mysqli_fetch_assoc($namecheck);
	$salt = $existinginfo["salt"];
	$hash = $existinginfo["hash"];
	$nom = $existinginfo["nom"];
	$prenom = $existinginfo["prenom"];

	$loginhash = crypt($password,$salt);
	
	if($hash != $loginhash){
		echo "6: Incorrect password ";
		exit();
	}

	echo "0\t".$nom."\t".$prenom;





?>