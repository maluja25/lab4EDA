#include<stdio.h>
#include<stdlib.h>
#define Nodo struct Nodo
#define Hijo struct Hijo
#define Lista struct Lista

Nodo
{
    int dato;
    Nodo *siguiente;
    Hijo *adyacencia;    
};
Hijo
{
	int peso;
    Nodo *hijo;
    Hijo *siguiente;
};
Lista{
    //declaramos el tamano del arreglo 
  int tamano;
  //nodo inicio y nodo fin
  Nodo *inicio;
  Nodo *fin; //por comodidad por si piden el el ultimo dato
};
void inicializar(Lista *lista){
  // a la lista que ingresa le apuntaremos a inicio y fin un NULL y al tamano = 0;
  lista->inicio = NULL;
  lista->fin = NULL;
  lista->tamano= 0;
}
void insertarNodo(Lista *lista,int N){
    Nodo *aux;
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->dato = N;
    nuevo->siguiente = NULL;
    nuevo->adyacencia = NULL;
    if(lista->tamano == 0){
    lista->inicio = nuevo;
    lista->fin = nuevo;
    lista->tamano++;
    }
    else{
    lista->tamano++;
    lista->fin->siguiente = nuevo;
    lista->fin = nuevo;
  }
}
void agregarHijo(Nodo *aux1 , Nodo *aux2 , Arista *nuevo){
    Arista *a;
    if(aux1->adyacencia == NULL){
        aux1->adyacencia = nuevo;
        nuevo->vrt = aux2;
    }else{
        a = aux1->adyacencia;
        while(a->siguiente != NULL){
            a = a->siguiente;
        }
        nuevo->vrt = aux2;
        a->siguiente = nuevo; 
    }
}
void insertarHijo(Lista *lista,int ini,int fin,int peso){
    Arista *nuevo = (Arista *)malloc(sizeof(Arista));
    nuevo->siguiente = NULL;
    nuevo->peso = peso;
    Nodo *aux1,*aux2;
    aux1 = lista->inicio;
    aux2 = lista->inicio;
    while(aux2 != NULL){
        if(aux2->dato == fin ){
            break;
        }
        aux2 = aux2->siguiente;
    }
    while(aux1 != NULL){
        if(aux1->dato ==ini){
            agregarHijo(aux1,aux2,nuevo);
        }
        aux1 = aux1->siguiente;
    }
}
void visualizarGrafo(Lista *lista){
    Nodo *aux=lista->inicio;
    Arista  *ar;
    printf("Nodos\n");
    while(aux!=NULL){   
        printf("%i:    ",aux->dato);
        if(aux->adyacencia!=NULL){
            ar=aux->adyacencia;
            while(ar!=NULL){ 
                printf(" %i",ar->vrt->dato);
                //printf("(%i)",ar->peso);
                ar=ar->siguiente;
            }
        }
        printf("\n");
        aux=aux->siguiente;
    }
    printf("\n");
}
/*
struct nodo {
    int proceso;
    int NumeroGenes;
    int *Genes;
    struct nodo *izq;
    struct nodo *der;
};

struct nodo *raiz=NULL;
struct nodo* busca(int key, struct nodo* ptr) {        // buscar key
	if(key == ptr->proceso){
		//printf("%i",ptr->proceso);
		return ptr;
	}
	if(ptr->izq != NULL){
		if(ptr->izq->proceso == key){
			return ptr->izq;
		}else if (ptr->izq->proceso != key){
			return busca(key,ptr->izq);
		}
	}
	if(ptr->der != NULL){
		if(ptr->der->proceso == key){
			return ptr->der;
		}else if(ptr->der->proceso != key){
			return busca(key,ptr->der);
		}
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
    
}
*/
/*
void insertare(int pro,int x){
	struct nodo *nuevo;
    nuevo = malloc(sizeof(struct nodo));
    nuevo->proceso = x;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    if(raiz == NULL){
    	raiz = nuevo;
    }
    struct nodo *rama;
   	rama = busca(pro,raiz);
   	//printf("rama %i\n",rama->proceso);
   	if(rama->izq == NULL){
   		rama->izq = nuevo;
   	}else if(rama->der == NULL){
   		rama->der = nuevo;
   	}
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
*/
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
int nodoRaiz = 0;
void leerArchivoProcesos(){
    FILE *ArchivoProcesos = fopen("procesos.in","r");
    char aux;
    int numero;
    while(aux != ' ' && aux != '\n'){
        aux = fgetc(ArchivoProcesos);
        char *num;
        num = &aux;
        //printf("%c",aux);
        numero = atoi(num);
        //printf("el numero es %i\n",numero);
        if(numero > 0){
            cantidadVertices = numero;
        }
    }
    printf("la cantidadVertices = %i\n",cantidadVertices);
    aux = fgetc(ArchivoProcesos);
    while(aux != '\n'){
        aux = fgetc(ArchivoProcesos);
        char *num;
        num = &aux;
        //printf("%c",aux);
        numero = atoi(num);
        //printf("el numero es %i\n",numero);
        if(numero > 0 ){
        	nodoRaiz = numero;
        }
        //printf("el caracter es = %c\n",aux);
    }
    fclose(ArchivoProcesos);
    ArchivoProcesos = fopen("procesos.in","r");
    printf("el nodoRaiz es :%i\n",nodoRaiz);
    insertar(nodoRaiz);
    ArchivoProcesos = fopen("procesos.in","r");
    aux = fgetc(ArchivoProcesos);
    int numero1,numero2;
    while(aux != EOF){
    	aux = fgetc(ArchivoProcesos);
    	if(aux == 'P'){
    		aux = fgetc(ArchivoProcesos);
    	}
    	if(aux == ' '){
    		aux = fgetc(ArchivoProcesos);
    		aux = fgetc(ArchivoProcesos);
    		char *num;
        	num = &aux;
        	//printf("%c",aux);
        	numero1 = atoi(num);
        	printf("%i",numero1);
        	//insertare(numero1,numero2);
    	}
    	if(aux == '\n'){
    		aux = fgetc(ArchivoProcesos);
    		aux = fgetc(ArchivoProcesos);
    		char *num;
        	num = &aux;
        	//printf("%c",aux);
        	numero2 = atoi(num);
    		printf("\n");
    		printf("el numero es %i",numero2);
    		//insertare(numero2,numero1);
    		printf("\t");
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
            printf("<-");
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
	Lista *lista = (Lista *)malloc(sizeof(Lista));
	inicializar(lista);
    leerArchivoProcesos();
    printf("\n\n\n\n\n\n");
    leerArchivoGenes();
    printf("\n");
    /*
    insertar(50);
    insertar(25);
    insertar(30);
    insertar(15);
    insertar(10);
    insertar(12);
    */
    //printf("\t\t");
    insertare(1,2);
    insertare(1,3);
    insertare(2,4);
    insertare(3,5);
    //insertare(4,6);
    imprimir(raiz);
    printf("\n");
    struct nodo *rama = busca(5,raiz);
    if(rama != NULL){
    	printf("rama %i\n",rama->proceso);
    }else{
    	printf("NULLql\n");
    }
    
    //imprimir(raiz);
    //printf("rama %i\n",rama->proceso);
    
    //insertare(2,4);
    printf("\n");
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