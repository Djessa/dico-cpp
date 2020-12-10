#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int choice(0);
    string mot, line;
    ifstream file("dico");
    ofstream fileO("dico", ios::app);
    cout<<"==== DICO NUMERIQUE ====\n"<<endl;
    cout<<"1.Chercher un mot."<<endl;
    cout<<"2.Ajouter un mot."<<endl<<"\tVotre choix : ";
    cin>>choice;
    cin.ignore();
    if(choice == 1)
    {
        if(file)
        {
            cout << "Entrer un mot en anglais : " << endl;
            getline(cin, mot);
            while(getline(file, line))
            {
                if(mot == line)
                {
                    getline(file, line);
                    cout <<endl<<"Signification : "<<endl<<"\t"+line<< endl;
                    return 0;
                }
            }
            cout<<"Mot introuvable"<<endl;
        }
        else
        {
            cout << "Erreur : Impossible d'ouvrir le fichier" << endl;
        }
    }
    else if(choice == 2)
    {
        file.close();
        if(fileO)
        {
            cout << "Entrer un mot en anglais : "<<endl;
            getline(cin, line);
            fileO<<line;
            cout << "Entrer sa signification en français : "<<endl;
            getline(cin, line);
            fileO<<endl<<line;
            cout<<"Un mot avec sa signification a bien été ajouté avec succès"<<endl;
        }
        else
        {
            cout << "Erreur : Impossible d'ouvrir le fichier"<<endl;
        }
    }
    return 0;
}
