#include<stdio.h>
#include<stdlib.h>
#define Nodo struct Nodo
#define Padre struct Padre
#define Lista struct Lista

Nodo
{
    int dato;
    int cantidadGenes;
    int *genes;
    Nodo *siguiente;
    Nodo *anterior;
    Padre *adyacencia;    
};
Padre
{
	Nodo *padre;
	Padre *siguiente;
};
Lista{
    //declaramos el tamano del arreglo 
  int tamano;
  //nodo inicio y nodo fin
  Nodo *inicio;
  Nodo *fin; //por comodidad por si piden el el ultimo dato
};
Lista *lista;
void inicializar(Lista *lista){
  // a la lista que ingresa le apuntaremos a inicio y fin un NULL y al tamano = 0;
  lista->inicio = NULL;
  lista->fin = NULL;
  lista->tamano= 0;
}
void insertarGen(Lista *lista,int proceso,int gen){
    Nodo *aux;
    aux = lista->inicio;
    while(aux->dato != proceso){
        aux = aux->siguiente;
    }
    aux->cantidadGenes++;
    aux->genes = (int *)realloc(aux->genes,sizeof(int )*(aux->cantidadGenes));
    aux->genes[aux->cantidadGenes-1] = gen;
}
void insertarNodo(Lista *lista,int N){
    Nodo *aux;
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->dato = N;
    nuevo->cantidadGenes = 0;
    nuevo->genes = (int *)malloc(sizeof(nuevo->cantidadGenes));
    nuevo->siguiente = NULL;
    nuevo->adyacencia = NULL;
    if(lista->tamano == 0){
    nuevo->anterior = NULL;
    lista->inicio = nuevo;
    lista->fin = nuevo;
    lista->tamano++;
    }
    else{
    lista->tamano++;
    nuevo->anterior = lista->fin;
    lista->fin->siguiente = nuevo;
    lista->fin = nuevo;
  }
}
void agregarPadre(Nodo *aux1 , Nodo *aux2 , Padre *nuevo){
    Padre *a;
    if(aux1->adyacencia == NULL){
        aux1->adyacencia = nuevo;
        nuevo->padre = aux2;
    }else{
        a = aux1->adyacencia;
        while(a->siguiente != NULL){
            a = a->siguiente;
        }
        nuevo->padre = aux2;
        a->siguiente = nuevo; 
    }
}
int cantidadVertices = 0;
int nodoRaiz = 0;

void insertarPadre(Lista *lista,int ini,int fin){
    Padre *nuevo = (Padre *)malloc(sizeof(Padre));
    nuevo->siguiente = NULL;
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
            agregarPadre(aux1,aux2,nuevo);
        }
        aux1 = aux1->siguiente;
    }
}
void ImprimirAR(){
	Nodo *aux=lista->fin;
	while(aux != NULL){
		printf("%i\n",aux->dato);
		aux = aux->anterior;
	}

}
void visualizarGrafo(){
    Nodo *aux=lista->inicio;
    Padre  *ar;
    printf("\nNodos\n");
    while(aux!=NULL){   
        printf("%i:    ",aux->dato);
        if(aux->adyacencia!=NULL){
            ar=aux->adyacencia;
            while(ar!=NULL){ 
                printf(" %i",ar->padre->dato);
                //printf("(%i)",ar->peso);
                ar=ar->siguiente;
            }
        }
        
        //printf("la cantidadGenes es :%i  ",aux->cantidadGenes);
        if(aux->cantidadGenes != 0){
            int i = 0;
            printf("\t");
            printf("tiene como genes a");
            while(i < aux->cantidadGenes){
                printf(" G%i",aux->genes[i]);
                i++;
            }
        }
        //holaaaaa jasdjasjdajsdasjd
        //jaja arregla esta wea
        
        printf("\n");
        aux=aux->siguiente;
    }
    printf("\n");
}
void leerArchivoGenes(){
    FILE *ArchivoGenes = fopen("genes.in","r");
    char aux;
    int numero,numero1;
    while(aux != EOF ){
        aux = fgetc(ArchivoGenes);
        if(aux == 'G'){
            aux = fgetc(ArchivoGenes);
            char *num;
            num = &aux;
            //printf("%c",aux);
            numero = atoi(num);
            //printf("G%i",numero);
            //insertar(numero);
        }
        if(aux == ' '){
            printf(" ");
            aux = fgetc(ArchivoGenes);
        }
        if(aux == 'P'){
            aux = fgetc(ArchivoGenes);
            char *num;
            num = &aux;
            //printf("%c",aux);
            numero1 = atoi(num);
            //printf("%i",numero1);
            insertarGen(lista,numero1,numero);
        }
        //printf("%c",aux);
        if(aux == '\n'){
            printf("\n");
        }
    }
}
Lista *leerArchivoProcesos(){
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    inicializar(lista);
    FILE *ArchivoProcesos = fopen("procesos.in","r");
    char aux;
    int numero;
    while(aux != ' ' && aux != '\n'){
        aux = fgetc(ArchivoProcesos);
        char *num;
        num = &aux;
        numero = atoi(num);
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
        numero = atoi(num);
        if(numero > 0 ){
            nodoRaiz = numero;
        }
    }
    fclose(ArchivoProcesos);
    ArchivoProcesos = fopen("procesos.in","r");
    printf("el nodoRaiz es :%i\n",nodoRaiz);
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
        }
        if(aux == '\n'){
            //printf("\n");
            aux = fgetc(ArchivoProcesos);
            aux = fgetc(ArchivoProcesos);
            char *num;
            num = &aux;
            numero1 = atoi(num);
            insertarNodo(lista,numero1);
        } 
    }
    fclose(ArchivoProcesos);
    ArchivoProcesos = fopen("procesos.in","r");
    aux = fgetc(ArchivoProcesos);
    printf("e%c",aux);
    while(aux != EOF){
    	aux = fgetc(ArchivoProcesos);
    	if(aux == '\n'){
    		printf("\n");
    		aux = fgetc(ArchivoProcesos);
    		aux = fgetc(ArchivoProcesos);
    		char *num;
            num = &aux;
            numero1 = atoi(num);
    		printf("%i",numero1);
    		
    	}
    	if(aux == 'P'){
    		aux = fgetc(ArchivoProcesos);
    		char *num;
            num = &aux;
            numero2 = atoi(num);
    		printf(":%i",numero2);
    		insertarPadre(lista,numero1,numero2);
    	}
    	   	
    }
    //aux = fgetc(ArchivoProcesos); por si las moscas , lo descomentamos.
    /*
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
            numero1 = atoi(num);
            insertarPadre(lista,numero1,numero2);
        }
        if(aux == '\n'){
            aux = fgetc(ArchivoProcesos);
            aux = fgetc(ArchivoProcesos);
            char *num;
            num = &aux;
            numero2 = atoi(num);
        }
    }
    */
    return lista;
}
void imprimirGenes(Lista *lista){
    Nodo *aux=lista->inicio;
    Padre  *ar;
    printf("\nNodos\n");
    while(aux!=NULL){   
        printf("%i:    ",aux->dato);
        if(aux->cantidadGenes != 0){
            printf("la cantidadGenes es %i",aux->cantidadGenes);
            int i = 0;
            while(i < aux->cantidadGenes){
                printf("G%i",aux->genes[i]);
                i++;
            }
            
        }
        printf("\n");
        aux=aux->siguiente;
    }
    printf("\n");
}
int SimilitudWP(int proceso1,int proceso2){






}
int main()
{

    lista = leerArchivoProcesos();
    leerArchivoGenes();
    visualizarGrafo();
    ImprimirAR();
    //imprimirGenes(lista);
    //printf("hola qlos");
    //insertarGen(lista,3,1);
    
    //leerArchivoGenes();
    return 0;
}