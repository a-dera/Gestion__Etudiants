#include <stdio.h>
int op;
char rep;
typedef struct  { // déclaration en utilisant typedef
      int matricule;
      char* nom[30];
      char* prenom[30];
      int age;
                }Etudiant; // Nom du type
Etudiant e; // déclaration des variables
void presentation()
	{
      system("title PROGRAMME DE GESTION D'ETUDIANTS");
	  printf("\t\t****************************************************\n");
	  printf("\t\t*                                                  *\n");
	  printf("\t\t*         PROGRAMME DE GESTION D'ETUDIANTS         *\n");
	  printf("\t\t*             ------------------------             *\n");
	  printf("\t\t*                                                  *\n");
	  printf("\t\t*OOOO          Auteur : Am\x82\x64\x82\x65 DERA             OOO*\n");
      printf("\t\t*              ******                              *\n");
	  printf("\t\t*                                                  *\n");
	  printf("\t\t*                      version 0.9                 *\n");
	  printf("\t\t*                                                  *\n");
	  printf("\t\t****************************************************\n");


	}
 /*-------Fonction de recherche------*/
 int rech(int matrech)
 {
     FILE*F;
     F=fopen("Etudiant.txt","r+");//ouverture du fichier en lecture simple
     do
    {
        fscanf(F,"%d ;%s ;%s ;%d \n",&e.matricule,&e.nom,&e.prenom,&e.age);
        fflush(stdin);
        if(e.matricule == matrech)
        {
           fclose(F);
           return 1;
        }
     }
      while(!feof(F));//rencontre de la fin de mon fichier---->fin de la boucle
      fclose(F);
     return -1;
 }
 /*---------Fonction d'ajout d'un étudiant----*/
  AjouterEtudiant()
 {
    FILE*F;
    int matrech;
    char choix;
    F=fopen("Etudiant.txt","a+");// ouverture du fichier en lecture écriture
    printf("\n Entrer la matricule du nouveau Etudiant: ");
    scanf("%d",&matrech);
    fflush(stdin);
    /*while(rech(matrech) == 1)//comparaison avec les matricules existants
    {
        printf("\n Cette matricule existe!");
        printf("\n Entrer à nouveau la matricule du nouveau Etudiant: ");
        scanf("%d",&matrech);
    }*/
    e.matricule=matrech;
    printf("\n Entrer le Nom de l'Etudiant: ");
    scanf("%s",&e.nom);
    printf("\n Entrer le Prenom de l'Etudiant: ");
    scanf("%s",&e.prenom);
    printf("\n Entrer l'age de l'Etudiant: ");
    scanf("%d",&e.age);
    fwrite(&e ,sizeof(e),1,F);
    printf("\n\t\t\t***Ajout avec succes***\n");
    printf("\n\t-------------Voici les informations-------------\n");
    printf("\t------------------------------------------------");
    printf(" \n          Matricule \t Nom \t Prenom \t Age");
    printf("\n\t     %d \t",e.matricule);
    printf("       %s \t",e.nom);
    printf("   %s \t",e.prenom);
    printf("  %d\n",e.age);
    fclose(F);//fermeture du fichier après l'ajout
    printf("\n--- Taper ""O"" ou ""o"" pour ajouter un autre Etudiant--- \n---Saisir une autre touche sinon --- : ");//Possibilité e faire plusieurs ajouts
	scanf("%s", &choix);
	 if (choix =='o' ||choix=='O' )
        {
      return AjouterEtudiant();
        }
    system("pause");
    return main();
 }
 /*------Fonction Affichage-----*/
 AfficherContenu()
 {
     FILE*F;
     F = fopen("Etudiant.txt","r");
     int i=0;
    if (F == NULL) printf("\n\t\t  +* fichier vide *+ ! \n");
 	else{
 		printf("\t------------Contenu du fichier------------------\n");

        printf("\t------------------------------------------------\n");
        printf(" \n    Ordre   Matricule \t Nom \t Prenom \t Age\n");
     while(fread(&e,sizeof(e),1,F))
	        {

         i++;
         printf("\n\t %d ",i);
         printf("\t %d \t",e.matricule);
         printf(" %s\t",e.nom);
         printf("  %s \t",e.prenom);
         printf("  \t%d\n",e.age);
      } fclose(F);
 	}

    system("pause");
    return main();
 }
 /*------Fonction de Vidation de tout le contenu----*/
  ViderContenu()
 {
            FILE* Fich, *F;
            F = fopen("Etudiant.txt","a+");// ouverture de notre fichier en lecture écriture
            Fich = fopen("TempEtudiant.txt","a+");// création d'un fichier intermédiare
            fclose(Fich);
            fclose(F);
            remove("Etudiant.txt");
            //rename("TempEtudiant.txt","Etudiant.txt");
            printf("\n  Contenu vid\x82 avec succes!\n");
            system("pause");
            return main();
 }
 /*---Fonction de Recherche et d'Affichage ---*/
  CherchEtud()
 {
     int matrech;// recherche par matricule
     printf("\n Entrer la matricule de l'Etudiant: ");
     scanf("%d",&matrech);
     FILE*fichier;
     fichier=fopen("Etudiant.txt","r+");//ouverture du fichier en lecture simple
   // do
    //{
        fscanf(fichier,"%d ;%s ;%s ;%d \n",&e.matricule,&e.nom,&e.prenom,&e.age);
        fflush(stdin);
        if( e.matricule== matrech)//affichage des infos correspondantes
        {
            printf("-------Informations sur l' Etudiant----\n\n");
            printf("\nMatricule :\t %d",e.matricule);
            printf("\nNom :\t\t %s",e.nom);
            printf("\nPrenom :    \t %s",e.prenom);
            printf("\nAge :\t\t %d\n",e.age);
        }
        else {
            printf("\nCette matricule n'existe pas encore\n");
        }
    // }
    // while(!feof(fichier));
     fclose(fichier);
      system("pause");
    return main();
 }

 /*-------Fonction de Modification------*/
 ModifEtud( matrech)
 {
    int i;
    char rep;
    printf("\n Entrer la matricule de l'Etudiant \x85 modifier: ");
    scanf("%d",&matrech);
    fflush(stdin);
    if(rech(matrech) == 1)
    {
        printf("\nModifier VRAIMENT? O/N: ");
        scanf("%s",&rep);
        fflush(stdin);
        if(rep =='o' || rep=='O')
        {
            FILE*fichier;
            FILE *Fich;
            fichier=fopen("Etudiant.txt","r");
            Fich=fopen("Temp.txt","w");
            //do
           // {
                //fread(&e,sizeof(e),1,F);
                fscanf(fichier,"%d ;%s ;%s ;%d ",&e.matricule,&e.nom,&e.prenom,&e.age);
                if(matrech==e.matricule)
                {
                    e.matricule=matrech;
                    printf("\n Entrer le Nouveau Nom: ");
                    scanf("%s",&e.nom);
                    printf("\n Entrer le Nouveau Prenom: ");
                    scanf("%s",&e.prenom);
                    printf("\n Entrer le Nouveau age: ");
                    scanf("%d",&e.age);
                    //fprintf(fichier,"%d ;%s ;%s ;%d \n",&e.matricule,&e.nom,&e.prenom,&e.age);
                    fwrite(&e, sizeof(e), 1, Fich);//écriture des news infos dans le new fichier
                }
            //}
           // while (!feof(F));
            fclose(fichier);
            fclose(Fich);
            remove("Etudiant.txt");
            rename("Temp.txt", "Etudiant.txt");
            printf("\n    **La modification a r\x82ussi!**\n");
            printf("\n\t--------Voici les nouvelles informations--------\n");
            printf("\t---------------------------------------------");
            printf(" \n          Matricule \t Nom \t Prenom \t Age");
            printf("\n\t    %d \t\t",e.matricule);
            printf(" %s   \t",e.nom);
            printf("   %s \t",e.prenom);
            printf("\t%d\n",e.age);
            fclose(fichier);
        }
        else
        {
           printf("\n La modification a \x82\x63hou\x82\n");
        }
    }
    else
    {
        printf("\n Cette matricule n'existe pas\n");
    }
    system("pause");
    return main();
}

 /*---------Procédure de suppression------*/
 SupprEtud()
 {
    char rep;//la réponse pour la confirmation de suppression
    int matrech;
    printf("Entrer la matricule de l'Etudiant \x85 supprimer: ");
    scanf("%d",&matrech);
    fflush(stdin);
    if(rech(matrech) == 1)
    {
        printf("\n\tConfirmer la suppression en tapant O\n\tou taper une autre touche pour annuler:");
        scanf("%s",&rep);
        //fflush(stdin);
        if(rep == 'o' || rep == 'O')// Pour gérer la casse
        {

            FILE *fichier;
            fichier = fopen("Etudiant.txt","r");
            FILE *Fich;
            Fich= fopen("Temp.txt","a");
            do
                {
                    fscanf(fichier,"%d ;%s ;%s ;%d \n",&e.matricule,&e.nom,&e.prenom,&e.age);
                    if(matrech!= e.matricule)
                    {
                      fprintf(Fich,"%d ;%s ;%s ;%d \n",&e.matricule,&e.nom,&e.prenom,&e.age);
                    }
                }
                while(!feof(fichier));

                fclose(Fich);
                fclose(fichier);
                //fclose(Fich);
                remove("Etudiant.txt");
                rename("Temp.txt","Etudiant.txt");
                printf("\nEtudiant supprimer avec succ\x83s!\n");
        }
        else
        {
            printf("\n Suppression annul\x82\x65\n");
        }
    }
     else //if(rech(matrech) == -1) //gestion du cas où la matricule n'existe pas dans le fichier
    {
        printf("\n Cette matricule n'existe pas encore!");
    }
    system("pause");
    return main();
 }


 main()
{
	system("cls");
	presentation();
	 system("pause");
	 system("cls");
    int op;//options du menu
    system("title PROGRAMME DE GESTION D'ETUDIANTS");
    system("cls");
    printf("\t\t\t\t       MENU \n");
    printf("\t\t\t-------------------------------- \n");
    printf("\t\t\t| 1>> Ajouter un Etudiant      |\n");
    printf("\t\t\t|                              |\n");
    printf("\t\t\t| 2>> Afficher tout le contenu |\n");
    printf("\t\t\t|                              |\n");
    printf("\t\t\t| 3>> Supprimer un Etudiant    |\n");
    printf("\t\t\t|                              |\n");
    printf("\t\t\t| 4>> Modifier un Etudiant     |\n");
    printf("\t\t\t|                              |\n");
    printf("\t\t\t| 5>> Vider tout le contenu    |\n");
    printf("\t\t\t|                              |\n");
    printf("\t\t\t| 6>> Rechercher un Etudiant   |\n");
    printf("\t\t\t|                              |\n");
    printf("\t\t\t| 7>> Quitter le programme     |\n");
    printf("\t\t\t|------------------------------|\n");

        printf("\n Entrer votre choix: ");
        scanf("%d", &op);

    switch (op)
    {
    case 1:AjouterEtudiant();
        break;
    case 2:AfficherContenu();
        break;
    case 3:SupprEtud();
        break;
    case 4:ModifEtud();
        break;
    case 5:ViderContenu();
        break;
    case 6:CherchEtud();
        break;
    case 7:system("exit");
        break;
    default :
		printf("Vous devez choisir un chiffre figurant dans le MENU!!!\n");
		system("pause");
		return main();
		break;
    }
}
