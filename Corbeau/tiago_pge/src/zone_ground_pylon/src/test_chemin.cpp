#include <ros/ros.h>
#include <stdio.h>
#include <math.h>
#include <iostream>



int main( int argc, char** argv )
{
  ros::init(argc, argv, "test");

  int numOfPoints = 12;
  double radius = 2;
  // draw the circle 
  double** points = 0;
  points = new double*[3];

	for (int h = 0; h < 3 ; h++){
		points[h] = new double[numOfPoints];
		for (int n = 0; n < numOfPoints; n++){
			points[h][n] = 0;
		}
	}

	float pas =  2*M_PI/numOfPoints;
	int k = 0;

	for (float angle=0; angle<2*M_PI; angle+=pas){
		points[0][k] = (double) points[0][k] + radius * cos(angle);
		points[1][k] = (double) points[1][k] + radius * sin(angle);
		points[2][k] = 1.2/numOfPoints * k;
		k++;
	}


	for (int j = 0; j < 3; j++){
		for (int i =0; i < numOfPoints; i++){
			std::cout << (points[j][i]);
			std::cout << (" ");
		}
		std::cout << ("\n");
	}


// Recuperation du points le plus proche sur le cercle
	double bestPt = INFINITY;
	double distance;
	int indice; 
	double point[1] = {0}; 

	std::array<double,2> pointOrigine = { {20,-10} };
	
	for (int i = 0; i < numOfPoints; i++){
		if( points[0][i] - pointOrigine[0] == 0 || points[1][i] - pointOrigine[1] == 0)
			std::cout << "Attention division par 0";
		distance = sqrt(pow(points[0][i] - pointOrigine[0], 2)) + sqrt(pow(points[1][i] - pointOrigine[1], 2));
		std::cout << std::endl << distance << std::endl;
		if(distance < bestPt){
			bestPt = distance;
			indice = i;
		}
	}

	std::array<double,3> pointEntreeCercle = { {0,0,0} };
	int indicePointEntree = indice; 
	std::cout << std::endl << indicePointEntree << std::endl;
	pointEntreeCercle[0] = points[0][indice];
	pointEntreeCercle[1] = points[1][indice];
	pointEntreeCercle[2] = points[2][indice];

	std::cout << "Le point le plus proche de l'origine est : " << pointOrigine[0] << " " << pointOrigine[1] << " est : " << std::endl;
	std::cout << pointEntreeCercle[0] << " " << pointEntreeCercle[1] << " " << pointEntreeCercle[2] << " !!!" << std::endl;
	
	std::array<double,2> pointGoal = { {-20,30} };

	bestPt = INFINITY;
	for (int i = 0; i < numOfPoints; i++){
		if( points[0][i] - pointGoal[0] == 0 || points[1][i] - pointGoal[1] == 0)
			std::cout << "Attention division par 0";
		distance = sqrt(pow(points[0][i] - pointGoal[0], 2)) + sqrt(pow(points[1][i] - pointGoal[1], 2));
		if(distance < bestPt){
			bestPt = distance;
			indice = i;
		}
	}
	std::array<double,3> pointSortieCercle = { {0,0,0} };
	int indicePointSortie = indice;
	pointSortieCercle[0] = points[0][indice];
	pointSortieCercle[1] = points[1][indice];
	pointSortieCercle[2] = points[2][indice];
	

	std::cout << "Le point le plus proche du but est : " << pointGoal[0] << " " << pointGoal[1] << " est : " << std::endl;
	std::cout << pointSortieCercle[0] << " " << pointSortieCercle[1] << " " << pointSortieCercle[2] << " !!!" << std::endl;
	


	// on a donc le point d'origine et le point but,
	// le point d'entree le plus proche de l'origine, 
	// le point de sortie le plus proche du but
	// il reste a déterminer le chemin sur le cercle le plus rapide
	// passant par le point d'entree, sortant par le point de sortie

	std::vector <std::vector<double> > chemin1(3,std::vector<double>(numOfPoints)); // (1, std::vector<double>(3));

	std::cout << std::endl << "entree indice : " << indicePointEntree << "  indiceSortie : " << indicePointSortie << std::endl;

	int cptChemin1;
	std::cout << "Chemin num 1 : ";
	for(int j = 0; j < 3; j++){
		std::cout << std::endl;
		cptChemin1 = 0;

		for(int i = indicePointEntree; i != indicePointSortie ; i = ((i+1) % numOfPoints)){

			//std::cout << std::endl << " indice : " << i << std::endl;
			chemin1[j][cptChemin1] = points[j][i];
			//std::cout << "points " << points[j][i] << std::endl << "chemin " << chemin1[j][cptChemin1] << std::endl;
			cptChemin1++;
			
		}
	}
	
	std::cout << std::endl;

	
	std::vector <std::vector<double> > chemin2(3,std::vector<double>(numOfPoints)); 

	int cptChemin2;
	std::cout << "Chemin num 2 : ";
	for(int j = 0; j < 3; j++){
		std::cout << std::endl;
		cptChemin2 = 0;

		for(int i = indicePointEntree; i != indicePointSortie ; i-- ){ // parcours dans l'autre sens 

			if(i < 0 ){ // pour gerer la discontinuite de maniere similaire au modulo 
				i = numOfPoints;
			}

			chemin2[j][cptChemin2] = points[j][i];
			//std::cout << "points " << points[j][i] << std::endl << "chemin " << chemin2[j][cptChemin2] << std::endl;
			cptChemin2++;
			
		}
	}
	
	std::cout << std::endl;

	std::cout << std::endl << "Chemin 1 : " << cptChemin1;
	std::cout << std::endl << "Chemin 2 : " << cptChemin2;

	std::cout << std::endl; 
	if(cptChemin1 < cptChemin2){
		for(int i = 0; i < cptChemin1; i++){
				std::cout << std::endl;
			for(int j = 0; j < 3; j++){
				std::cout << chemin1[j][i] << " ";
			}
		}
	}
	else
	{
		for(int i = 0; i < cptChemin2; i++){
			std::cout << std::endl;
			for(int j = 0; j < 3; j++){
				std::cout << chemin2[j][i] << " ";
			}
		}
	}
	
	

	

//---- end draw circle

printf("\n\rFin du run\n\r");
}
