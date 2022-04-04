#include <iostream>
#include <fstream>
#include <string.h>
#pragma warning(disable : 4996)

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

// variabile
char matrix[101][101];
char matrix_of_outputs[101][101];
int n_states;
int n_strings;
int n_transitions;
char transition;
int n_last_states;
int first_state, next_state, initial_state, last_state[101];
char output;
char aux[256];

struct words
{
	char word[256], current_state;
}v[1001];


void is_accepted(char word[], int current_state)
{
	int i, j, k, l;
	bool ok = true;
	int path[101] = { 0 };	// drum parcurs
	char list_of_outputs[101] = { 0 };	// caractere afisate
	int cont1 = 0;
	int cont2 = 0;
	while (ok == true)
	{
		path[cont1] = current_state;	// memorare drum
		cont1++;
		int remember = 0;
		for (i = 0; i < n_states; i++)
		{
			if (matrix[current_state][word[0]] == i)
				remember = i;	// memorare stare
		}

		int stop = 0;
		if (remember == 0)
		{
			for (j = 0; j < n_last_states && stop == 0; j++)
				if ((current_state == last_state[j])&&strlen(word)==0)
				{
					// daca starea finala este o stare curenta si am ajuns la ultima litera, cuvantul este acceptat
					fout << "DA\n";
					for (k = 0; k < cont2; k++)
						fout << list_of_outputs[k]; // afisare outputs
					fout << '\n';
					fout << "Traseu: ";
					for (l = 0; l < cont1; l++)
						fout << path[l] << " "; // afisare traseu
					fout << '\n';
					stop = 1;
					ok = false;  // iesim din subprogram
				}
			if (!stop)
			{
				fout << "NU\n";		// daca nu este stare finala sau cuvantul mai are litere de parcurs, cuvantul nu este acceptat
				strcpy(word, "0");
				ok = false;  // iesim din subprogram
			}
		}
		else
		{
			list_of_outputs[cont2] = matrix_of_outputs[current_state][word[0]];		// memoram output-ul
			cont2++;
			current_state = remember;	// trecem la urmatoarea stare
			strcpy_s(aux, word + 1);	// stergem litera verificata
			strcpy(word, aux);
		}
	}
}

int main()
{
	int i;

	fin >> n_states; // numar de stari
	fin >> n_transitions; // numar de tranzitii

	for (i = 0; i < n_transitions; i++)
	{
		// stari, tranzitii si caractere ce trebuie afisate
		fin >> initial_state >> next_state >> transition >> output;
		matrix[initial_state][transition] = next_state;
		matrix_of_outputs[initial_state][transition] = output;
	}

	fin >> first_state; // starea de la care pleaca
	fin >> n_last_states; // numarul starilor finale
	for (i = 0; i < n_last_states; i++)
		fin >> last_state[i]; // stari finale

	fin >> n_strings; // numarul cuvintelor

	for (i = 0; i < n_strings; i++)
	{
		fin >> v[i].word; // cuvant verificat
		v[i].current_state = first_state; // starea curenta
		is_accepted(v[i].word, v[i].current_state); // apelare subprogram care verifica daca este acceptat sau nu cuvantul 
	}
	return 0;
}