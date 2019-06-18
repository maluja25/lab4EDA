#include<stdio.h>
#include<stdlib.h>

struct nodo {
    int proceso;
    int NumeroGenes;
    int *Genes;
    struct nodo *izq;
    struct nodo *der;
};

struct nodo *raiz=NULL;
struct nodo* busca(int key, struct nodo* ptr) {        // buscar key
  if (key == ptr->proceso) return ptr;      // Ok. encuentro!
  if (key < ptr->proceso) {           // debe estar en la rama izquierda
    if (ptr->izq == NULL) return NULL;  // no existe
    busca(key, ptr->izq);         // enlace ocupado: seguir buscando
  }
  if (key > ptr->proceso) {           // debe estar en la rama derecha
    if (ptr->der == NULL) return NULL;  // no existe
    busca(key, ptr->der);         // enlace ocupado: seguir buscando
  }
  return NULL;
}
void insertarGen(struct nodo *raiz,int numeroProceso,int Gen){
    struct nodo *aux = busca(numeroProceso,raiz);
    if(aux->NumeroGenes == 1){
        aux->NumeroGenes++;
    }else{
        aux->NumeroGenes = 1;
    }
    
    //buscar un nodo con el numero del proceso
    /*
    numerodegen++;
    genes[numerodegen-1] = gen;
    */
}
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
void leerArchivoGenes(){
	FILE *ArchivoGenes = fopen("genes.in","r");
	char aux;
	int numero;
	while(aux != EOF ){
		aux = fgetc(ArchivoGenes);
		if(aux == 'G'){
			aux = fgetc(ArchivoGenes);
			char *num;
        	num = &aux;
        	//printf("%c",aux);
        	numero = atoi(num);
        	printf("%i",numero);
        	//insertar(numero);
		}
	}
}
int cantidadVertices = 0;
void leerArchivoProcesos(){
    FILE *ArchivoProcesos = fopen("procesos.in","r");
    char aux;
    int numero;
    while(aux != '\n'){
        aux = fgetc(ArchivoProcesos);
        char *num;
        num = &aux;
        //printf("%c",aux);
        numero = atoi(num);
        printf("el numero es %i\n",numero);
        if(numero > 0){
            cantidadVertices = numero;
        }
    }
    printf("la cantidadVertices %i\n",numero);
    aux = fgetc(ArchivoProcesos);
    while(aux != '\n'){
        aux = fgetc(ArchivoProcesos);
        char *num;
        num = &aux;
        //printf("%c",aux);
        numero = atoi(num);
        printf("el numero es %i\n",numero);
        //printf("el caracter es = %c\n",aux);
    }
    while(aux != EOF){
        aux = fgetc(ArchivoProcesos);
        if(aux == 'P' /*|| aux == ' '*/){
            aux = fgetc(ArchivoProcesos);
        }
        if(aux != ' ' && aux != '\n'){
        	char *num;
        	num = &aux;
        	//printf("%c",aux);
        	numero = atoi(num);
        	printf("%i",numero);
        }
        /*
        if(numero != 0){
        	printf("%i",numero);
        }
        */
        if(aux == '\n'){
            printf("\n");
        }
    }

}
void imprimir(struct nodo *reco){
    if (reco != NULL)
    {
        printf("%i",reco->proceso);
        if(reco->izq != NULL){
            //printf("\\");
            printf("\n");
            //printf("P%i",reco->proceso);
            //printf("<-");
            imprimir(reco->izq);
        }
        if(reco->der != NULL){
            printf("\n");
            //printf("\t\t\t");
            //printf("P%i",reco->proceso);
            printf("->");
            imprimir(reco->der);
        }
    }
}
int main()
{
    leerArchivoProcesos();
    printf("\n\n\n\n\n\n");
    leerArchivoGenes();
    printf("\n");
    insertar(50);
    insertar(25);
    insertar(30);
    insertar(15);
    insertar(10);
    insertar(12);
    printf("\t\t");
    imprimir(raiz);
    /*
    insertar(100);
    insertar(50);
    insertar(25);
    insertar(75);
    insertar(150);
    */
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