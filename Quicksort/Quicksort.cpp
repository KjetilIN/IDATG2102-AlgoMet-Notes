#include <iostream>
using namespace std;

const int N = 10;

/**
 *  Skriver ut (deler av) arrayen 'arr' sitt innhold.
 *
 *  @param   tekst    -  Ledetekst som skrives aller først
 *  @param   arr      -  Arrayen som får (deler av) innholdet skrevet ut
 *  @param   venstre  -  Nedre/venstre indeks for utskrift
 *  @param   hoyre    -  Øvre/høyre    indeks for utskrift
 */
void display(const string &tekst, const char arr[],
             const int venstre, const int hoyre)
{
    char tegn;
    cout << tekst << "\t";
    for (int i = venstre; i <= hoyre; i++)
        cout << arr[i];
    cin >> tegn; //  Venter på ETT tegn og '\n'.
}

/**
 * @brief Swap two elements by refrence
 *
 * @param a
 * @param b
 */
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int part(char arr[], const int left, const int right)
{
    if (right > left)
    {                           //  Minst TO elementer:
        int i, j;               //  Indekser som går mot hverandre.
        char partisjonsElement; //  Partisjonselementet.

        partisjonsElement = arr[right]; //  Initierer til HØYRE element.
        i = left - 1;                   //  Initierer indeksene til ETT
        j = right;                      //    hakk utenfor intervallet.
                                        //  NB:  'i' og 'j' økes/minskes FØR bruk.
                                        //       Derfor er de initiert utenfor grensene.
                                        //       De stopper dermed på de aktuelle
                                        //       indekser UTEN å "hoppe" en for langt.
        display("\nBefore:", arr, left, right);
        while (true)
        { //  Looper til breaker ut:
          //  Leter etter STØRRE ELLER LIK:
            while (arr[++i] < partisjonsElement)
                ; //  NB:  Tom innmat !!!
                  //  Leter etter MINDRE ELLER LIK:
            while (arr[--j] > partisjonsElement)
                cout << j << "\n"; //  NB:  Tom innmat !!!

            cout << "i: " << i << "  j: " << j << "   - "
                 << ((i < j) ? "Switch" : "BREAK") << '\n';
            if (i >= j)
                break;            //  Indekser nådd/passert hverandre.
            swap(arr[i], arr[j]); //  Bytter der stanset med 'i' og 'j'.
        }

        swap(arr[i], arr[right]); //  Bytter/setter (for godt) partisjons-
                                  //    elementet med det HELT TIL HØYRE I
                                  //    VENSTRE HALVDEL (dvs. der 'i' er).
        display("After:", arr, left, right);
        return i; //  Returnerer der partisjonselementet
    }             //    havnet/ble plassert.
    return 0;     //  Mindre enn to elementer:
}

/**
 * @brief Quicksort method
 *
 * @param arr array given
 * @param left left index
 * @param right right index
 */

void quicksort(char arr[], int left, int right)
{
    if (right > left)
    {
        int index = part(arr,left,right);
        quicksort(arr, left, index - 1);
        quicksort(arr, index + 1, right);
    }
}

int main() {
    char array[N+1];                 //  Array som skal sorteres.
                                     //  Bruker indeksene 1-N
                                     //    da det ligger SENTINEL KEY
                                     //    (STOPPVERDI) i element nr.0 !!!

    srand(0);                      //  Brukes ifm. tilfeldighet/randomisering.

    array[0] = ' ';                //  Legger inn SENTINEL KEY !!!
    string word = "SLIMBILLEN";

    for (int i = 1; i <= N; i++) //  Array med tilfeldige bokstaver A-Z:
        array[i] = word[i-1];

    display("\n\nArrayen FØR sortering:\n", array, 1, N);


    quicksort(array, 1, N);      //  QUICKSORT SORTERER !!!

    display("\n\nArrayen ETTER QUICKSORT sortering:\n", array, 1, N);

    cout << "\n\n";
    return 0;
}