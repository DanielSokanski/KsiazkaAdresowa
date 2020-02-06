#include <iostream>
#include <windows.h>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

struct Adresat {
    string name, surname, phone, email, address;
    int id;
};

void addContact(vector<Adresat> &adresaci) {
    string name, surname, phone, email, address;
    int id;
    Adresat adresat;
    system("cls");
    if (adresaci.empty()) {
        adresat.id = adresaci.size();
    } else {
        adresat.id = adresaci[adresaci.size()-1].id+1;
    }
    cout<< "Podaj imie: ";
    cin>>name;
    adresat.name=name;
    cout<< "Podaj nazwisko: ";
    cin>>surname;
    adresat.surname=surname;
    cout<< "Podaj telefon: ";
    cin>>phone;
    adresat.phone=phone;
    cout<< "Podaj email: ";
    cin>>email;
    adresat.email=email;
    cin.sync();
    cout<< "Podaj adres: ";
    getline(cin, address);
    adresat.address=address;
    adresaci.push_back (adresat);
    fstream lista;
    lista.open("KsiazkaAdresow.txt",ios::out | ios::app);
    lista << adresat.id << "|";
    lista << adresat.name << "|";
    lista << adresat.surname << "|";
    lista << adresat.phone << "|";
    lista << adresat.email << "|";
    lista << adresat.address << "|"<< endl;
    lista.close();
    Sleep(2000);
}
void searchByName(vector<Adresat> adresaci) {

    string name;
    cout << "Wpisz imie szukanej osoby: ";
    cin >> name;
    for (int i=0; i<adresaci.size(); i++) {
        if (name==adresaci[i].name) {
            cout << "ID: "<<adresaci[i].id << endl;
            cout << "Imie: "<<adresaci[i].name << endl;
            cout << "Nazwisko: "<<adresaci[i].surname << endl;
            cout << "Numer telefonu: "<<adresaci[i].phone << endl;
            cout << "Adres email: "<<adresaci[i].email << endl;
            cout << "Adres: "<<adresaci[i].address << endl << endl;
        }
    }
    Sleep(2000);
}

void searchBySurname(vector<Adresat> adresaci) {
    string surname;
    cout << "Wpisz nazwisko szukanej osoby: ";
    cin >> surname;
    for (int i=0; i<adresaci.size(); i++) {
        if (surname==adresaci[i].surname) {
            cout << "ID: "<<adresaci[i].id << endl;
            cout << "Imie: "<<adresaci[i].name << endl;
            cout << "Nazwisko: "<<adresaci[i].surname << endl;
            cout << "Numer telefonu: "<<adresaci[i].phone << endl;
            cout << "Adres email: "<<adresaci[i].email << endl;
            cout << "Adres: "<<adresaci[i].address << endl << endl;
        }
    }
    Sleep(2000);
}
void deleteUser(vector<Adresat> &adresaci) {

    Adresat adresat;
    string name, surname, email, address, phone;
    int id;
    cout << "Wpisz ID osoby ktora chcesz usunac: ";
    cin >> id;
    for (int i=0; i<adresaci.size(); i++) {
        if (id==adresaci[i].id) {
            adresaci.erase(adresaci.begin()+i);
        }
    }
    fstream lista;
    lista.open("KsiazkaAdresow.txt",ios::out | ios::trunc);
    lista.close();
    lista.open("KsiazkaAdresow.txt",ios::out | ios::app);
    for (int i=0; i<adresaci.size(); i++) {
        lista << adresaci[i].id << "|";
        lista << adresaci[i].name << "|";
        lista << adresaci[i].surname << "|";
        lista << adresaci[i].phone << "|";
        lista << adresaci[i].email << "|";
        lista << adresaci[i].address << "|"<< endl;
    }
    lista.close();
    Sleep(2000);
}
void showAll(vector<Adresat> adresaci) {
    Adresat adresat;
    string name, surname, email, address, line, phone;
    fstream lista;
    lista.open("KsiazkaAdresow.txt",ios::in);
    if (lista.good()==true) {
        while(!lista.eof()) {
            getline(lista,line);
            cout << line << endl;
        }
        lista.close();
    } else {
        cout << "Ksiazka adresowa nie istnieje!" << endl;
    }
    cout << "Nacisnij spacje aby przejsc do glownego menu." << endl;
    system("pause");
}
void changingData(vector<Adresat> &adresaci) {
    Adresat adresat;
    string name, surname, phone, email, address;
    char option, decision;
    int id;
    cout << "Podaj ID osoby do modyfikacji: ";
    cin >> id;
    for (int i=0; i<adresaci.size(); i++){
    if (id==adresaci[i].id){
        system("cls");
        cout << "1 - Imie" << endl;
        cout << "2 - Nazwisko" << endl;
        cout << "3 - Numer telefonu" << endl;
        cout << "4 - Email" << endl;
        cout << "5 - Adres" << endl;
        cout << "6 - Powrot do menu" << endl;
        cout << "Twoj wybor: " << endl;
        cin >> option;
        if (option=='1') {
            cout << "Wpisz nowe imie: ";
            cin >> name;
            for (int i=0; i<adresaci.size(); i++) {
                if (id==adresaci[i].id) {
                    cout << "Zmieniasz obecne imie: " <<adresaci[i].name << " na imie: "<< name <<endl;
                    cout << "Czy zgadzasz sie na zmiane (t): ";
                    cin >> decision;
                    if ((decision=='t')||(decision=='T')) {
                        adresaci[i].name=name;
                        fstream lista;
                        lista.open("KsiazkaAdresow.txt",ios::out | ios::trunc);
                        lista.close();
                        lista.open("KsiazkaAdresow.txt",ios::out | ios::app);
                        for (int i=0; i<adresaci.size(); i++) {
                            lista << adresaci[i].id << "|";
                            lista << adresaci[i].name << "|";
                            lista << adresaci[i].surname << "|";
                            lista << adresaci[i].phone << "|";
                            lista << adresaci[i].email << "|";
                            lista << adresaci[i].address << "|"<< endl;
                        }
                        lista.close();
                    } else
                        exit(0);
                }
            }
        } else if (option=='2') {
            cout << "Wpisz nowe nazwisko: ";
            cin >> surname;
            for (int i=0; i<adresaci.size(); i++) {
                if (id==adresaci[i].id) {
                    cout << "Zmieniasz obecne nazwisko: " <<adresaci[i].surname << " na nazwisko: "<< surname <<endl;
                    cout << "Czy zgadzasz sie na zmiame (t): ";
                    cin >> decision;
                    if ((decision=='t')||(decision=='T')) {
                        adresaci[i].surname=surname;
                        fstream lista;
                        lista.open("KsiazkaAdresow.txt",ios::out | ios::trunc);
                        lista.close();
                        lista.open("KsiazkaAdresow.txt",ios::out | ios::app);
                        for (int i=0; i<adresaci.size(); i++) {
                            lista << adresaci[i].id << "|";
                            lista << adresaci[i].name << "|";
                            lista << adresaci[i].surname << "|";
                            lista << adresaci[i].phone << "|";
                            lista << adresaci[i].email << "|";
                            lista << adresaci[i].address << "|"<< endl;
                        }
                        lista.close();
                    } else
                        exit(0);
                }
            }
        } else if (option=='3') {
            cout << "Wpisz nowy numer telefonu: ";
            cin >> phone;
            for (int i=0; i<adresaci.size(); i++) {
                if (id==adresaci[i].id) {
                    cout << "Zmieniasz obecny numer telefonu: " <<adresaci[i].phone << " na numer: "<< phone <<endl;
                    cout << "Czy zgadzasz sie na zmiame (t): ";
                    cin >> decision;
                    if ((decision=='t')||(decision=='T')) {
                        adresaci[i].phone=phone;
                        fstream lista;
                        lista.open("KsiazkaAdresow.txt",ios::out | ios::trunc);
                        lista.close();
                        lista.open("KsiazkaAdresow.txt",ios::out | ios::app);
                        for (int i=0; i<adresaci.size(); i++) {
                            lista << adresaci[i].id << "|";
                            lista << adresaci[i].name << "|";
                            lista << adresaci[i].surname << "|";
                            lista << adresaci[i].phone << "|";
                            lista << adresaci[i].email << "|";
                            lista << adresaci[i].address << "|"<< endl;
                        }
                        lista.close();
                    } else
                        exit(0);
                }
            }
        } else if (option=='4') {
            cout << "Wpisz nowy adres email: ";
            cin >> email;
            for (int i=0; i<adresaci.size(); i++) {
                if (id==adresaci[i].id) {
                    cout << "Zmieniasz obecne email: " <<adresaci[i].email << " na email: "<< email <<endl;
                    cout << "Czy zgadzasz sie na zmiame (t): ";
                    cin >> decision;
                    if ((decision=='t')||(decision=='T')) {
                        adresaci[i].email=email;
                        fstream lista;
                        lista.open("KsiazkaAdresow.txt",ios::out | ios::trunc);
                        lista.close();
                        lista.open("KsiazkaAdresow.txt",ios::out | ios::app);
                        for (int i=0; i<adresaci.size(); i++) {
                            lista << adresaci[i].id << "|";
                            lista << adresaci[i].name << "|";
                            lista << adresaci[i].surname << "|";
                            lista << adresaci[i].phone << "|";
                            lista << adresaci[i].email << "|";
                            lista << adresaci[i].address << "|"<< endl;
                        }
                        lista.close();
                    } else
                        exit(0);
                }
            }
        } else if (option=='5') {
            cout << "Wpisz nowy adres: ";
            cin.sync();
            getline(cin, address);
            for (int i=0; i<adresaci.size(); i++) {
                if (id==adresaci[i].id) {
                    cout << "Zmieniasz obecny adres: " <<adresaci[i].address << " na adres: "<< address <<endl;
                    cout << "Czy zgadzasz sie na zmiame (t): ";
                    cin >> decision;
                    if ((decision=='t')||(decision=='T')) {
                        adresaci[i].address=address;
                        fstream lista;
                        lista.open("KsiazkaAdresow.txt",ios::out | ios::trunc);
                        lista.close();
                        lista.open("KsiazkaAdresow.txt",ios::out | ios::app);
                        for (int i=0; i<adresaci.size(); i++) {
                            lista << adresaci[i].id << "|";
                            lista << adresaci[i].name << "|";
                            lista << adresaci[i].surname << "|";
                            lista << adresaci[i].phone << "|";
                            lista << adresaci[i].email << "|";
                            lista << adresaci[i].address << "|"<< endl;
                        }
                        lista.close();
                    } else
                        exit(0);
                }
            }
        } else if (option=='6') {
            Sleep(2000);
        }
    }
    else
        Sleep(2000);
}
cout << "Nie ma osoby o takim ID w bazie danych";
Sleep(2000);
}
void loadingData(vector<Adresat> &adresaci) {
    string name, surname, phone, email, address;
    int id=0;
    Adresat adresat;
    vector<string> daneOsobowe;
    string linia;
    string temp = "";
    fstream lista;
    lista.open("KsiazkaAdresow.txt", ios::in);
    if(lista.good()==false)
        cout << "Nie mozna otworzyc pliku!";
    while(getline(lista, linia)) {
        int dlugoscLinii=0;
        dlugoscLinii=linia.length();
        for(int j=0; j<dlugoscLinii; j++) {
            if (linia[j] != '|') {
                temp = temp + linia[j];
            } else {
                daneOsobowe.push_back(temp);
                temp.clear();
            }
        }
        for (int j=0; j<daneOsobowe.size(); j++) {
            if (j%6==0)
                adresat.id=atoi(daneOsobowe[j].c_str());
            else if (j%6==1)
                adresat.name=daneOsobowe[j];
            else if (j%6==2)
                adresat.surname=daneOsobowe[j];
            else if (j%6==3)
                adresat.phone=daneOsobowe[j];
            else if (j%6==4)
                adresat.email=daneOsobowe[j];
            else if (j%6==5)
                adresat.address=daneOsobowe[j];
        }
        adresaci.push_back(adresat);
    }
    lista.close();
}
int main() {
    string name, surname, phone, email, address;
    int id;
    Adresat adresat;
    vector <Adresat> adresaci;
    fstream lista;
    lista.open("KsiazkaAdresow.txt",ios::out | ios::app);
    lista.close();
    loadingData(adresaci);
    int noOfUsers = adresaci.size();
    char selection;
    while(1) {
        system("cls");
        cout << "KSIAZKA ADRESOWA"<<endl;
        cout << "1. Dodaj adresata." << endl;
        cout << "2. Wyszukaj po imieniu." << endl;
        cout << "3. Wyszukaj po nazwisku." << endl;
        cout << "4. Wyswietl wszystkich adresatow." << endl;
        cout << "5. Usun adresata." << endl;
        cout << "6. Edytuj adresata." << endl;
        cout << "9. Zakoncz program." << endl;
        cout << "Twoj wybor:" << endl;
        cin >> selection;
        if (selection=='1') {
            addContact(adresaci);
        } else if (selection=='2') {
            searchByName(adresaci);
        } else if (selection=='3') {
            searchBySurname(adresaci);
        } else if (selection=='4') {
            showAll(adresaci);
        } else if (selection=='5') {
            deleteUser(adresaci);
        } else if (selection=='6') {
            changingData(adresaci);
        } else if (selection=='9') {
            exit(0);
        }
    }
    return 0;
}
