#include "Map.h"

int Map::funcionHash(string key, int rerun)
{
    int suma=0;
    for(int i=0;i<key.size();i++)
    {
        suma+=key[i];
    }
    return suma+rerun;
}

Map::Map()
{
    int size = 10000;
    array_key = new string[size];
    array_value = new int[size];

    for(int i=0;i<size;i++)
        array_key[i]="";
}

void Map::put(string key, int value)
{
    //Modificar este put porque cuando se encuentre un flag de deleted, esta posicion debe ser aprovechado y ponerse en este espacio

    int rerun = 0;
    int pos;
    do
    {
        pos = funcionHash(key,rerun);
        rerun++;
    }while(array_key[pos]!="" && array_key[pos] != "-1");

    array_key[pos]=key;
    array_value[pos]=value;
}

int Map::get(string key)
{
    //Cuando hago remove, el get tiene que seguri buscando cuandi encuentre este flag, ahorita se detendría donde encuenre D (flag deleted)
    //Y diria que no existe, asi que debe seguir buscando s

    int rerun = 0;
    int pos;
    do
    {
        pos = funcionHash(key,rerun);
        rerun++;

    }while(array_key[pos]!=key && array_key[pos] != "" &&  array_key[pos] != "-1" );
    //El array_key[pos] != null es porque si hay una key que no esta en el array, este quedaria en infinito, asi que hay que detenerlo

    if (array_key[pos] == "" || array_key[pos] == "-1")
        return -1;

    return array_value[pos];
}

bool Map::exists(string key)
{
    int value = get(key);

    if (value != -1){
        //cout<< "EXISTE " + key <<endl;
        return true;
    }

    //cout<< "NO EXISTE " + key <<endl;
    return false;
}

void Map::remove(string key)
{
    //Aplicar tecnica de escribir un flag en la posicion donde se encuentra la key

    //cout<< "Key remove " + key << endl;

    if (exists(key))
    {
        int rerun = 0;
        int pos;
        do
        {
            pos = funcionHash(key,rerun);
            rerun++;

        }while(array_key[pos]!=key && array_key[pos] != "" &&  array_key[pos] != "-1" );

        //cout<< "Pos remove " + pos << endl;
        //Flag -1 significa que esta borrado
        array_key[pos] = "-1";
    }
}
