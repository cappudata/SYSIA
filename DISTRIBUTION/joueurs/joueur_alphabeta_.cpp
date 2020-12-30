#include "joueur_alphabeta_.h"


Joueur_AlphaBeta_::Joueur_AlphaBeta_(std::string nom, bool joueur)
    :Joueur(nom,joueur)
{}



char Joueur_AlphaBeta_::nom_abbrege() const
{
    return 'A';
}



int min(int a,int b)
{
	return a < b ? a : b;
}

int max(int a,int b)
{
	return a > b ? a : b;
}

int alphaBeta(Jeu jeu,bool E,int a,int b)
{
	//std::cout << "Etat du jeu :" << jeu.etat()  << " ----> Meilleur Coup :" << a << std::endl;
	if(jeu.fini()) 
		if(E == true)
			return 1; 
		else	
			return -1;	
		
	else if(E == 1) // Joueur existenciel
	{
		int v = -9999;
		for(int i=0; i < jeu.nb_coups() ; i++)
		{
			Jeu copie = jeu;
			copie.joue(i);
			v = max(v, alphaBeta(copie,false,a,b));
			if( v >= b )
				return v;
			a = max(a,v);
			std::cout << "a = " << a << std::endl;

			return v;			
		}

	}
	else // Joueur Universel
	{
		int v = 9999;
		for(int i=0; i < jeu.nb_coups() ; i++)
		{
			Jeu copie = jeu;
			copie.joue(i);
			v = min(v, alphaBeta(copie,true,a,b));
			
			if( a >= v)
				return v;
			
			b = min(b,v);
			std::cout << "b = " << b << std::endl;
			return v;
		}
	}
}


void Joueur_AlphaBeta_::recherche_coup(Jeu jeu, int &coup)
{
	int meilleurCoup = 0;
	coup = 0;
	for(int i = 0 ; i < jeu.nb_coups() ; i++)
	{
		Jeu copie = jeu; // OK fonctionne
		copie.joue(i);
		std::cout << "c : " << jeu[i] << " Pour i : " << i << std::endl;
		if( alphaBeta(	copie,	true, -9999, 9999) == 1)
			if(jeu.coup_licite(i)){
				meilleurCoup = i;
			std::cout << "Le meilleurCoup est :" << meilleurCoup << std::endl;
			}
	}
	std::cout << "Le meilleurCoup est :" << meilleurCoup << std::endl;
	coup = meilleurCoup;
}