<?php
	
	$con = mysqli_connect('localhost', 'root','root','naavi_pge');
	//verifier connection
	if (mysqli_connect_errno())
	{
		echo "1: Connection failed";//error 1 ==  conection failed
		exit();
	}

	$identification = $_POST["identification"];
	$date = $_POST["date"];
	$pylone = $_POST["pylone"];
	$lieudit = $_POST["lieudit"];
	$lat = $_POST["lat"];
	$lon = $_POST["lon"];
	$deg = $_POST["deg"];
	$pluie = $_POST["pluie"];
	$vent = $_POST["vent"];
	$type = $_POST["type"];
	$hauteur = $_POST["hauteur"];

	//check if identification name exist
	$namecheckquery = "SELECT id FROM users WHERE identification='".$identification."';";
	$namecheck = mysqli_query($con,$namecheckquery) or die("2: Name query failed");
	
	$existinginfo = mysqli_fetch_assoc($namecheck);
	$id = $existinginfo["id"];

	//add info of mission
	$insertuserquery = "INSERT INTO mission (users, dates, pylones, lieudit, lat, lon, deg, pluie, vent, type,resultat,hauteur,lat_atterissage, lon_atterissage) VALUES ('". $id ."','". $date ."','". $pylone ."','" . $lieudit . "','" . $lat . "','" . $lon . "','" . $deg . "','" . $pluie . "','" . $vent . "','" . $type . "','" . "aucune erreur" . "','" . $hauteur . "','" . "pasencore" . "','" . "pasencore" . "');";
	mysqli_query($con, $insertuserquery) or die("4: insert mission query failed");


	echo "0";

	//add user to the table







?>