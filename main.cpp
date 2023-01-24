#include <iostream>
#include <string>
using namespace std;

class personne
{
private:
    const int cin;
    string nom;
    string prenom;
public:
    personne(int, string, string);
    int get_cin() const;
    string get_nom() const;
    string get_prenom() const;
    ~personne();
};
personne::personne(int c, string n, string p) :cin(c), nom(n), prenom(p) {}
int personne:: get_cin() const{
    return cin;
}
string personne::get_nom() const  {
    return nom;
}
string personne::get_prenom() const {
    return prenom;
}
personne::~personne(){}
class compte
{
private:
    const int num;
    double solde;
public:
    compte(const int, double);
    void deposer(double);
    void retirer(double);
    void set_solde(double);
    double get_solde();
    int getnumcompte();
    ~compte();
};
compte::compte(const int n, double s) : num(n) {
    if (s >= 0) {
        solde = s;
    }
}
int compte:: getnumcompte()
{
     return num;
}
void compte::set_solde(double a)
{
    solde=a;
}
double compte::get_solde()
{
    return solde;
}
void compte::deposer(double montant) {
    double s;
    s = get_solde();
    s += montant;
    set_solde(s);
}
void compte::retirer(double montant){
    double s;
    s = get_solde();
    if (s>= montant)
    {
        s -= montant;
        set_solde(s);
    }
    else
        cout<< "solde insuffisant"<<endl;
}
compte::~compte(){}

class banque
{
private:
    string nom;
    compte tab_compte[];
public:
    banque(string);
    void ajouter_compte();
    void fermer_compte();
    compte recherchecompte(int);
    int recherchep(int);
    ~banque();

};
banque::banque(string nm)
{
    nom = nm;
}

compte banque::recherchecompte(int nm) {
    int i;
    for (i=1;i<sizeof(tab_compte);i++)
    {
        if (tab_compte[i].getnumcompte()==nm)
            return tab_compte[i] ;
    }
    return tab_compte[0];
}
int banque::recherchep(int num) {
    int i;
    for (i=1;i<sizeof(tab_compte);i++)
    {
        if (tab_compte[i].getnumcompte()==num)
            return i ;
    }
    return 0;
}

void banque::ajouter_compte() {
    int pos;
    compte c;
    cout<<"donner le numero de compte"<<endl;
    cin<< c.num;
    cout<<"donner le solde de compte"<<endl;
    cin<< c.solde;
    pos= recherchep(0);
    if (pos==0)
        cout << "ERROOOOOOR "<<endl;
    else
    {

        tab_compte[pos]=c;
        cout << "la creation de compte se termine avec succes "<<endl;
    }
}
void banque::fermer_compte() {
    int pos,i,n;
    compte c;
    cout<<"donner le numero de compte"<<endl;
    cin<< c.num;
    pos= recherchep(c.num);
    if (pos==0)
        cout<< " compte introuvable" <<endl;
    else{
    for (i = pos; i < (n) - 1; i++)
        tab_compte[i] = tab_compte[i + 1];
    cout<< " compte ajouté" <<endl;
    }
}
void banque:: affiche(compte tab_compte)
{
    for (i=0;i<n;i++)
    {
        cout<<"le compte a pour numero" << tab_compte[i].num<<"possede un solde egale à "<< tab_compte[i].solde<<endl;
    }
}
int main()
{
    int i,ci;
    string nom, prenom;
    double solde,montant;
    personne p(12345678, "rania", "chakroun");
    compte c(8, 0000.0000);
    banque bank("biat");
    compte tab_compte[5];
    while (1)
    {
        cout << "**********************************************************************\n\tmenu\t\n**********************************************************************" << endl;
        cout << "1-savoir le cin" << endl;
        cout << "2-savoir le nom " << endl;
        cout << "3-savoir le prenom " << endl;
        cout << "4-savoir le solde du compte" << endl;
        cout << "5-deposer dans un compte" << endl;
        cout << "6-retirer d'un compte" << endl;
        cout << "7-ouvrir un compte" << endl;
        cout << "8-fermer un compte" << endl;
        cout << "9-chercher un compte" << endl;

        cout << "0-quitter" << endl;
        cout << "donner un entier entre 0 et 9 " << endl;
        cin >> i;
        switch (i)
        {
        case 1:
        {
            ci= p.get_cin();
            cout << "le cin est " << ci << endl;
            break;
        }

        case 2:
        {
            nom= p.get_nom();
            cout << "le nom est " << nom << endl;
            break;
        }
        case 3:
        {
            prenom= p.get_prenom();
            cout << "le prenom est " << prenom << endl;
            break;
        }
        case 4:
        {
            solde=c.get_solde();
            cout << "le solde est " << solde << endl;
            break;
        }
        case 5:
        {
            cout << "qu'elle est le montant vous voulez l'ajouter  " << endl;
            cin>> montant;
            c.deposer(8,montant);
            break;
        }
        case 6:
        {
            cout << "qu'elle est le montant vous voulez le retirer  " << endl;
            cin>> montant;
            c.retirer(8,montant);
            break;
        }
        case 7:
            {
            bank.ajouter_compte(c);
            break;
            }
        case 8:
            {
            bank.fermer_compte(c);
            break;
            }
        case 9
            {
            bank.recherchecompte(c);
            break;
            }

        case 0:
            exit(1);
        }

    }
    return 0;
}
