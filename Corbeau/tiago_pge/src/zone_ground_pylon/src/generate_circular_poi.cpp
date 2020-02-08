#include <zone_ground_pylon/generate_circular_poi.h>


using namespace zone_ground_pylon;

std::vector <std::vector<double> > Generate_circular_poi::generate_circle(int numOfPoints, double radius, double posOriX, double posOriY, double posOriZ  ){

//int numOfPoints = 60;
  //double radius = 50;
  // draw the circle 
  //double** points = 0;
  //points = new double*[3];

	/*for (int h = 0; h < 3 ; h++){
		points[h] = new double[numOfPoints];
		for (int n = 0; n < numOfPoints; n++){
			points[h][n] = 0;
		}
	}*/

    std::vector <std::vector<double> > points(3,std::vector<double>(numOfPoints));

	float pas =  2*M_PI/numOfPoints;
	int k = 0;

	for (float angle=0; angle<2*M_PI; angle+=pas){
		points[0][k] = (double) points[0][k] + radius * cos(angle) + posOriX;
		points[1][k] = (double) points[1][k] + radius * sin(angle) + posOriY;
		points[2][k] = 1.2/numOfPoints * k + posOriZ;
		k++;
	}


	for (int j = 0; j < 3; j++){
		for (int i =0; i < numOfPoints; i++){
			std::cout << (points[j][i]);
			std::cout << (" ");
		}
		std::cout << ("\n");
	}

    return points;
}


std::array<double,4> Generate_circular_poi::get_pt_proche(std::vector <std::vector<double> > cercle, std::array<double,3> pointProche ){
    // on retourne un array de 4, le dernier slot du tableau est réservé pour l'indice du point d'entree
    double bestPt = INFINITY;
	double distance;
	int indice; 

	double soustractionA; 
	double soustractionB;

    for (int i = 0; i < cercle[0].size(); i++){
		// on precalcule les soustraction pour tester 
		soustractionA = cercle[0][i] - pointProche[0];
		soustractionB = cercle[1][i] - pointProche[1];

		// pour traiter le cas de la racine de 0 
		if(soustractionA == 0 && soustractionB == 0) // les deux
			distance = 0;
		else // aucune 
			distance = sqrt(pow(soustractionA, 2) + (pow(soustractionB, 2)));

		if(distance < bestPt){
			bestPt = distance;
			indice = i;
		}
	}
    std::array<double,4> pointEntreeCercle = { {0,0,0,0} };
    
	pointEntreeCercle[0] = cercle[0][indice];
	pointEntreeCercle[1] = cercle[1][indice];
	pointEntreeCercle[2] = cercle[2][indice];
	pointEntreeCercle[3] = indice; // on ajoute l'indice par rapport au cercle 

    return pointEntreeCercle; 
}

std::vector <std::vector<double> > Generate_circular_poi::bestChemin(std::vector <std::vector<double> > cercle,
                                    std::array<double,4> pointEntree, 
                                    std::array<double,4> pointSortie){
    

    std::vector <std::vector<double> > chemin1(3,std::vector<double>()); // (1, std::vector<double>(3));

	int cptChemin1;
	//std::cout << "Chemin num 1 : ";
	for(int j = 0; j < 3; j++){
		//std::cout << std::endl;
		cptChemin1 = 0;

		for(int i = (int) pointEntree[3]; i != (int) pointSortie[3] ; i = ((i+1) % cercle[0].size())){

			
			chemin1[j].push_back(cercle[j][i]);
			//std::cout << "points " << points[j][i] << std::endl << "chemin " << chemin1[j][cptChemin1] << std::endl;
			cptChemin1++;
			
		}
	}
	
	// std::cout << std::endl;

	std::vector <std::vector<double> > chemin2(3,std::vector<double>()); 

	int cptChemin2;
	//std::cout << "Chemin num 2 : ";
	for(int j = 0; j < 3; j++){
		std::cout << std::endl;
		cptChemin2 = 0;

		for(int i = (int) pointEntree[3]; i != (int) pointSortie[3] ; i-- ){ // parcours dans l'autre sens 

			if(i < 0 ){ // pour gerer la discontinuite de maniere similaire au modulo 
				i = cercle[0].size();
			}

			chemin2[j].push_back(cercle[j][i]);
			//std::cout << "points " << cercle[j][i] << std::endl << "chemin " << chemin2[j][cptChemin2] << std::endl;
			cptChemin2++;
			
		}
	}

    if(cptChemin1 < cptChemin2) // on retourne le chemin le plus court
        return chemin1;
    else
        return chemin2;
}

// genere la trajectoire entre deux points en passant par le cercle de traj
std::vector <std::vector<double> > Generate_circular_poi::generate_traj_2pt_from_circle(
            std::vector <std::vector<double> > cercle, std::array<double,3> pointOrigine,
            std::array<double,3> pointGoal){
    
    std::array<double,4> ptEntree = Generate_circular_poi::get_pt_proche(cercle,pointOrigine);
    std::array<double,4> ptSortie = Generate_circular_poi::get_pt_proche(cercle,pointGoal);

    return Generate_circular_poi::bestChemin(cercle, ptEntree, ptSortie);
}


//    std::vector <std::vector<double> > cercle Generate_circular_poi::generate_circle()

int main( int argc, char** argv )
{
    Generate_circular_poi gen;
    //generation d'un cercle 
    std::vector <std::vector<double> > cercle = gen.generate_circle(60, 50.0, 0.0, 0.0, 0.0);

    // genrere les pts de passage
    std::array<double,3> pointOrigine = { { 20,10,0} };
    std::array<double,3> pointGoal    = { {-20,30,0} };

    std::vector <std::vector<double> > chemin = gen.generate_traj_2pt_from_circle(cercle, pointOrigine,pointGoal);

    for(int i = 0; i < chemin[0].size(); i++){
            std::cout << std::endl;
        for(int j = 0; j < 3; j++){
            std::cout << chemin[j][i] << " ";
        }
    }
}


