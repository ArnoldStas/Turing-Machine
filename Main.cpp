#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <conio.h>
#include <typeinfo>

using namespace std;

/*#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif*/

struct tiuring_1 {
    string pradine_busena;
    char pradine_reiksme = ' ';
    char pakeiciama_reiksme = ' ';
    char juostos_kryptis = ' ';
    string baigtine_busena;
};

struct tiuring_2 {
    string pradine_busena;
    char pradine_reiksme_T1 = ' ';
    char antrine_reiksme_T2 = ' ';
    char pradine_pakeiciama_reiksme_T1 = ' ';
    char antrine_pakeiciama_reiksme_T2 = ' ';
    char juostos_kryptis_T1 = ' ';
    char juostos_kryptis_T2 = ' ';
    string baigtine_busena;
};

void pranesimas();

int main()
{
    ifstream ived;
    int failo_numeris;

    //cout << ".txt";

    ived.open("Files/6.txt");

    if (!ived)
    {
        cout << "File is not provided.";
    }

    /*if (argc < 2)
        cout << "Nepateiktas argumentas";
    else {
        for (int i = 0; i < argc; ++i)
        {
            cout << "argv[" << i << "]= " << argv[i] << endl;
            cout << "argv[" << i << "]= " << "uzima: " << sizeof(argv[i]) << " baitus" << endl;
            cout << "argc[" << i << "]= " << "duomens tipas : " << typeid(argv[i]).name() << endl;
        }

    }*/

    //system("pause");

    int line_number;
    ived >> line_number;


    try
    {
        if (line_number > 2 || line_number < 1) throw line_number;
    }
    catch (int error_1)
    {
        cout << "Pateiktas netinkamas juostu kiekis";
        return 1;
    }

    if (line_number == 1)
    {
        string line;
        ived >> line;

        /*cout << line;
        cout << endl;*/

        int reader_position;
        ived >> reader_position;
        reader_position--;

        vector<tiuring_1> temptiuring;
        tiuring_1 temp;

        int kiekis = 0;

        while (!ived.eof())
        {
            ived >> temp.pradine_busena >> temp.pradine_reiksme >> temp.pakeiciama_reiksme >> temp.juostos_kryptis >> temp.baigtine_busena;
            temptiuring.emplace_back(temp);
            kiekis++;
        }

        /*for (int i = 0; i < kiekis; i++)
        {
            cout << temptiuring[i].pradine_busena << " " << temptiuring[i].pradine_reiksme << " " << temptiuring[i].pakeiciama_reiksme << " " << temptiuring[i].juostos_kryptis << " " << temptiuring[i].baigtine_busena << endl;
        }*/

        vector<char> eil_simboliai;
        vector<char> reading_line_symbols;

        char x = ' ';
        char y = ' ';

        long long eil_kiekis = line.size();

        for (int i = 0; i < eil_kiekis; i++)
        {
            eil_simboliai.emplace_back(line[i]);
            if (i != reader_position) reading_line_symbols.emplace_back(y);
            else reading_line_symbols.emplace_back('^');
        }

        /*for (int i = 0; i < eil_kiekis; i++)
        {
            cout << eil_simboliai[i];
        }
        cout << endl;
        for (int i = 0; i < eil_kiekis; i++)
        {
            cout << reading_line_symbols[i];
        }*///JUOSTOS ATSPAUSDINIMAS IR GALVUTES JUOSTOS ATSPAUSDINIMAS

        string k = "0";
        int klaida = 1;
        int tikr = 0;

        while (true)
        {
            //cout << klaida;

            if (klaida == 0)
            {
                cout << "|Tiuring machine has stopped because of UNKNOWN statement {" << k << "}| " << endl;
                break;
            }

            klaida = 0;

            for (int i = 0; i < kiekis; i++)
            {
                if (temptiuring[i].pradine_busena == k)
                {

                    if (temptiuring[i].pradine_reiksme == eil_simboliai[reader_position])
                    {

                        klaida++;

                        eil_simboliai[reader_position] = temptiuring[i].pakeiciama_reiksme;
                        if (temptiuring[i].juostos_kryptis == 'R')
                        {
                            reading_line_symbols[reader_position] = ' ';
                            if (reader_position >= eil_kiekis - 1)
                            {
                                eil_simboliai.emplace_back(' ');
                                reading_line_symbols.emplace_back('^');
                            }
                            reader_position++;
                            reading_line_symbols[reader_position] = '^';
                        }

                        if (temptiuring[i].juostos_kryptis == 'L')
                        {
                            reading_line_symbols[reader_position] = ' ';
                            if (reader_position == 0)
                            {
                                eil_simboliai.insert(eil_simboliai.begin(), ' ');
                                reading_line_symbols.insert(reading_line_symbols.begin(), ' ');
                            }
                            else reader_position--;
                            reading_line_symbols[reader_position] = '^';
                        }

                        k = temptiuring[i].baigtine_busena;
                    }
                }

            }

            system("cls");


            for (int i = 0; i < eil_kiekis; i++)
            {
                cout << eil_simboliai[i];
            }

            cout << endl;

            for (int i = 0; i < eil_kiekis; i++)
            {
                cout << reading_line_symbols[i];
            }

            cout << endl;

            if (_kbhit())
            {
                int input = _getch();
                if (input == 13) // 13 ASCII kodas for ENTER
                {
                    cout << "The loop is endless. System stopped." << endl;
                    break;
                }
            }

            pranesimas();

            if (tikr > 100000)
            {
                cout << "Program has detected infinity loop." << endl;
            }

            tikr++;
        }

        ived.close();
        return 0;
    }
    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    else {

        string line_1;
        ived >> line_1;
        string line_2;
        ived >> line_2;

        /*cout << line_1 << endl;
        cout << line_2;
        cout << endl;*/

        int reader_position_1;
        int reader_position_2;

        ived >> reader_position_1;
        reader_position_1--;
        ived >> reader_position_2;
        reader_position_2--;

        vector<tiuring_2> temptiuring_1;
        tiuring_2 temp_1;

        int kiekis = 0;

        while (!ived.eof())
        {
            ived >> temp_1.pradine_busena;

            ived >> temp_1.pradine_reiksme_T1 >> temp_1.antrine_reiksme_T2;
            ived >> temp_1.pradine_pakeiciama_reiksme_T1 >> temp_1.antrine_pakeiciama_reiksme_T2;
            ived >> temp_1.juostos_kryptis_T1 >> temp_1.juostos_kryptis_T2;

            ived >> temp_1.baigtine_busena;

            temptiuring_1.emplace_back(temp_1);
            kiekis++;
        }

        /*for (int i = 0; i < kiekis; i++)
        {
            cout << temptiuring_1[i].pradine_busena << " " << temptiuring_1[i].pradine_reiksme_T1 << " " << temptiuring_1[i].pakeiciama_reiksme_T1 << " " << temptiuring_1[i].juostos_kryptis_T1 << " " << temptiuring_1[i].baigtine_busena << endl;
        }*/

        vector<char> eil_simboliai_1;
        vector<char> reading_line_symbols_1;

        vector<char> eil_simboliai_2;
        vector<char> reading_line_symbols_2;

        long long eil_kiekis_1 = line_1.size();
        long long eil_kiekis_2 = line_2.size();

        char x = ' ';
        char y = ' ';

        for (int i = 0; i < eil_kiekis_1; i++)
        {
            eil_simboliai_1.emplace_back(line_1[i]);
            if (reader_position_1 != i) reading_line_symbols_1.emplace_back(y);
            else reading_line_symbols_1.emplace_back('^');
        }

        for (int i = 0; i < eil_kiekis_2; i++)
        {
            eil_simboliai_2.emplace_back(line_2[i]);
            if (reader_position_2 != i) reading_line_symbols_2.emplace_back(y);
            else reading_line_symbols_2.emplace_back('^');
        }

        /*for (int i = 0; i < eil_kiekis_1; i++)
        {
            cout << eil_simboliai_1[i];
        }
        cout << endl;
        for (int i = 0; i < eil_kiekis_1; i++)
        {
            cout << reading_line_symbols_1[i];
        }{1} JUOSTOS ATSPAUSDINIMAS IR GALVUTĖS JUOSTOS ATSPAUSDINIMAS
        cout << endl;
        for (int i = 0; i < eil_kiekis_2; i++)
        {
            cout << eil_simboliai_2[i];
        }
        cout << endl;
        for (int i = 0; i < eil_kiekis_2; i++)
        {
            cout << reading_line_symbols_2[i];
        }*///{2} JUOSTOS ATSPAUSDINIMAS IR GALVUTĖS JUOSTOS ATSPAUSDINIMAS

        string busena_1 = "0";
        string busena_2 = "0";
        int klaida = 1;
        int tikr = 0;

        while (true)
        {

            if (klaida == 0)
            {
                cout << "|First line tiuring machine has stopped because of UNKNOWN statement {" << busena_1 << "}| " << endl;
                cout << "|Second line tiuring machine has stopped because of UNKNOWN statement {" << busena_2 << "}| " << endl;
                break;
            }

            klaida = 0;

            for (int i = 0; i < kiekis; i++)
            {
                if (busena_1 == temptiuring_1[i].pradine_busena && eil_simboliai_1[reader_position_1] == temptiuring_1[i].pradine_reiksme_T1 && eil_simboliai_2[reader_position_2] == temptiuring_1[i].antrine_reiksme_T2)
                {
                    klaida++;

                    eil_simboliai_1[reader_position_1] = temptiuring_1[i].pradine_pakeiciama_reiksme_T1;
                    eil_simboliai_2[reader_position_2] = temptiuring_1[i].antrine_pakeiciama_reiksme_T2;

                    if (temptiuring_1[i].juostos_kryptis_T1 == 'R')
                    {
                        reading_line_symbols_1[reader_position_1] = ' ';
                        if (reader_position_1 >= eil_kiekis_1)
                        {
                            eil_simboliai_1.emplace_back(' ');
                            reading_line_symbols_1.emplace_back(' ');
                        }
                        else reader_position_1++;
                        reading_line_symbols_1[reader_position_1] = '^';
                    }

                    if (temptiuring_1[i].juostos_kryptis_T1 == 'L')
                    {
                        reading_line_symbols_1[reader_position_1] = ' ';
                        if (reader_position_1 == 0)
                        {
                            eil_simboliai_1.insert(eil_simboliai_1.begin(), ' ');
                            reading_line_symbols_1.insert(reading_line_symbols_1.begin(), ' ');
                        }
                        else reader_position_1--;
                        reading_line_symbols_1[reader_position_1] = '^';
                    }

                    if (temptiuring_1[i].juostos_kryptis_T2 == 'R')
                    {
                        reading_line_symbols_2[reader_position_2] = ' ';
                        if (reader_position_2 >= eil_kiekis_2 - 1)
                        {
                            eil_simboliai_2.emplace_back(' ');
                            reading_line_symbols_2.emplace_back(' ');
                        }
                        else reader_position_2++;
                        reading_line_symbols_2[reader_position_2] = '^';
                    }

                    if (temptiuring_1[i].juostos_kryptis_T2 == 'L')
                    {
                        reading_line_symbols_2[reader_position_2] = ' ';
                        if (reader_position_2 == 0)
                        {
                            eil_simboliai_2.insert(eil_simboliai_2.begin(), ' ');
                            reading_line_symbols_2.insert(reading_line_symbols_2.begin(), ' ');
                        }
                        else reader_position_2--;
                        reading_line_symbols_2[reader_position_2] = '^';
                    }

                    busena_1 = temptiuring_1[i].baigtine_busena;
                    busena_2 = temptiuring_1[i].baigtine_busena;
                }

            }

            system("cls");

            for (int i = 0; i < eil_kiekis_1; i++)
            {
                cout << eil_simboliai_1[i];
            }

            cout << endl;

            for (int i = 0; i < eil_kiekis_1; i++)
            {
                cout << reading_line_symbols_1[i];
            }

            cout << endl;

            for (int i = 0; i < eil_kiekis_2; i++)
            {
                cout << eil_simboliai_2[i];
            }

            cout << endl;

            for (int i = 0; i < eil_kiekis_2; i++)
            {
                cout << reading_line_symbols_2[i];
            }

            cout << endl;

            if (_kbhit())
            {
                int input = _getch();
                if (input == 13) // 13 ASCII kodas for ENTER
                {
                    cout << "The loop is endless. System stopped." << endl;
                    break;
                }
            }

            pranesimas();

            if (tikr > 100000)
            {
                cout << "Program has detected infinity loop." << endl;
            }

            tikr++;

        }

        ived.close();
        return 0;
    }
}

void pranesimas()
{
    cout << "|If the lines/line are/is endless, press {ENTER} key to stop|" << endl;
    cout << endl;
}

