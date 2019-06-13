#include<stdio.h>
#include<stdlib.h>

struct nodo {
    int proceso;
    struct nodo *izq;
    struct nodo *der;
};

struct nodo *raiz=NULL;

void insertar(int x)
{
    struct nodo *nuevo;
    nuevo = malloc(sizeof(struct nodo));
    nuevo->proceso = x;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    if (raiz == NULL)
        raiz = nuevo;
    else
    {
        struct nodo *anterior, *reco;
        anterior = NULL;
        reco = raiz;
        while (reco != NULL)
        {
            anterior = reco;
            if (x < reco->proceso)
                reco = reco->izq;
            else
                reco = reco->der;
        }
        if (x < anterior->proceso)
            anterior->izq = nuevo;
        else
            anterior->der = nuevo;
    }
}

void imprimirPre(struct nodo *reco)
{
    if (reco != NULL)
    {
        printf("%i-",reco->proceso);
        imprimirPre(reco->izq);
        imprimirPre(reco->der);
    }
}


void imprimirEntre(struct nodo *reco)
{
    if (reco != NULL)
    {
        imprimirEntre(reco->izq);
        printf("%i-",reco->proceso);
        imprimirEntre(reco->der);
    }
}

void imprimirPost(struct nodo *reco)
{
    if (reco != NULL)
    {
        imprimirPost(reco->izq);
        imprimirPost(reco->der);
        printf("%i-",reco->proceso);
    }
}

void borrar(struct nodo *reco)
{
    if (reco != NULL)
    {
        borrar(reco->izq);
        borrar(reco->der);
        free(reco);
    }
}
void leerArchivo(){
    FILE *ArchivoProcesos = fopen("procesos.in","r");
    char aux;
    while(aux != EOF){
        aux = fgetc(ArchivoProcesos);
        printf("%c",aux);
    }

}

int main()
{
    leerArchivo();
    insertar(100);
    insertar(50);
    insertar(25);
    insertar(75);
    insertar(150);
    /*
    printf("Impresion preorden: ");
    imprimirPre(raiz);
    printf("\n\n");
    printf("Impresion entreorden: ");
    imprimirEntre(raiz);
    printf("\n\n");
    printf("Impresion postorden: ");
    imprimirPost(raiz);
    borrar(raiz);
    printf("\n\n");
    */
    return 0;
}