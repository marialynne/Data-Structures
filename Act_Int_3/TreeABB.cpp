// Manuel Camacho Padilla [A0142315]
// Arbol de estructura de datos (ABB)
#include "TreeABB.h"
 
TreeABB::TreeABB(){
  root = nullptr;
}

TreeABB::~TreeABB(){
  
}

//getters
NodeABB* TreeABB::getRoot(){
  return root;
}

//setters
void TreeABB::setRoot(NodeABB* _root){
  root = _root;
}

//funtions 
void TreeABB::pre_order(NodeABB* aux){ 
  /*
  Funcion recursiva que imprime los nodos de la estrcutura de arriba a abjo e izquierda a derecha.
  Input: Un objeto tipo NodeABB
  Output: Nada
  */ 
  if(aux != nullptr){
    std::cout << aux;
    pre_order(aux->getLeft());
    pre_order(aux->getRight());
  }
}

void TreeABB::in_order(NodeABB* aux){
  /*
  Funcion recursiva que imprime los nodos de la estrcutura de manera ordenara. 
  Input: Un objeto tipo NodeABB
  Output: Nada
  */ 
  if(aux != nullptr){
    in_order(aux->getLeft());
    std::cout << aux;
    in_order(aux->getRight());
  }
}

void TreeABB::insert(int data, string texto){
  /*
  Funcion que inserta un nuevo nodo en la estructura ABB.
  Input: Un valor tipo entero [data]
         Un valot tipo string [texto]
  Output: Nada
  */ 
  NodeABB* nuevo = new NodeABB(data, nullptr, nullptr, texto);
  if(root==nullptr){
    root = nuevo;
  }
  else{ // Recorre el arbol
    NodeABB* aux1 = root; 
    NodeABB* aux2 = root; 
    while(aux2 != nullptr && aux2->getData() != nuevo->getData()){
      aux1 = aux2;
      if(aux1->getData() < nuevo->getData()){
        aux2 = aux2->getRight();
      }
      else{
        aux2 = aux2->getLeft();
      }
    } // ---
    if(aux2 != nullptr){
      std::cout << "\nDato repetido: " << nuevo->getData() << "\nRemoved...\n" <<  std::endl;
      delete nuevo;
    } // Inserta raices subsecuentes 
    else{
      if(aux1->getData() < nuevo->getData()){
        aux1->setRight(nuevo);
      }
      else{
        aux1->setLeft(nuevo);
      }
    }
  }
}

NodeABB* TreeABB::find_b(int n){
  /* 
  Funcion que recorre la estructura para validar si un dato existe en la estructura. 
  Input: Un valor entero 
  Output: Un valor booleano
  */
  NodeABB* aux = root;

  while(aux != nullptr && aux->getData() != n){

    if(n < aux->getData()){
      aux = aux->getLeft();
    }
    else{
      aux = aux->getRight();
    }
  }
  
  return aux;
  
}

NodeABB* TreeABB::previous(NodeABB* n){
  /*
  Función que recibirá un objeto y devolverá el objeto anterior a ella.
  Input: Un objeto Node 
  Output: Un objeto Node
  */
    NodeABB* before = root;
    NodeABB* right = root;
    NodeABB* left = root, *aux = root;

    if(n == root){
      //std::cout << "El nodo es raiz\n" << std::endl;
      return n;
    }
    while(before != nullptr && before->getData() != n->getData()){

      aux = before;

      right = before->getRight();
      left = before->getLeft();

      if(right != nullptr){
        if(n->getData() < before->getData()){
          before = before->getLeft();
        }
        else{
          before = before->getRight();
        }
      }
      else if(left != nullptr){
        if(n->getData() < before->getData()){
          before = before->getLeft();
        }
        else{
          before = before->getRight();
        }
      }
      else{
        break;
      }
      
    }

    return aux;
}

void TreeABB::removed(int n){
  /* 
  Funcion que borra un objeto dentro de la estructura. Hará llamado de la función find_b para validar si existe ese dato. Posteriormente un objeto auxiliar recorrerá el árbol y borrará el objeto con el valor dado. 
  Input: Un valor entero 
  Output: Nada 
  */
  if(find_b(n) != nullptr || n == root->getData()){
   
    NodeABB* aux = root;
    NodeABB* left = root; 
    NodeABB* right = root;

    while(aux->getData() != n && aux != nullptr){

      if(n < aux->getData()){
        aux = aux->getLeft();
      }
      else{
        aux = aux->getRight();
      }
    }
    
    left = aux->getLeft();
    right = aux->getRight();

    NodeABB* before = previous(aux);

    // SI HAY UNA SOLA RAMA
    if((right !=  nullptr && left == nullptr) || (left != nullptr && right == nullptr)){

      std::cout << "\nremoved[TRUE]:  Se borra nodo con una sola rama.";
      removed_a(before,aux);

    }
    // SI TIENE DOS RAMAS
    else if(left != nullptr && right != nullptr){

      std::cout << "\nremoved[TRUE]:  Se borra nodo con dos ramas.";
      removed_b(before,aux);

    }
    // SI ES HOJA
    else{
      std::cout << "\nremoved[TRUE]:  Se borra nodo que es hoja.";
      removed_c(before,aux);

    }
    // FIN
    std::cout << "\n\t\t\t\tDato \"" << n << "\" eliminado." << std::endl;
  }
  
  // SI NO EXISTE 
  else{
    std::cout << "\nremoved[FALSE]: No existe el dato \"" << n <<"\" en el rabol.\n" << std::endl;
  }
}

NodeABB* TreeABB::removed_c(NodeABB*antes, NodeABB*aux){
  /* 
  Función que borra el nodo si es hoja.
  Input: Un objeto tipo Node [antes]
           Un objeto tipo Node [aux (el que se borra)]
  Output: Objeto tipo Node [padre del nodo que se borro]
  */
  if(aux == root){
    setRoot(nullptr);
    return nullptr;
  }
  else{
    if(antes->getRight() == aux)
      antes->setRight(nullptr);
    else
      antes->setLeft(nullptr);
    return antes;
  }
}

NodeABB* TreeABB::removed_b(NodeABB*antes, NodeABB*aux){ 
  /* 
  Función que borra el nodo si tiene dos ramas u hojas.
  Input: Un objeto tipo Node [antes]
           Un objeto tipo Node [aux (el que se borra)]
  Output: Objeto tipo Node [padre del nodo que se borro]
  */
  NodeABB* antesd = aux->getRight(), *auxd = antesd;
  while(auxd->getLeft() != nullptr){ // busco sustituto del nodo que borro, el mas izquierdo de la derecha
    antesd = auxd;
    auxd = auxd->getLeft();
  }
  if(aux == root){// el nodo que borro es raiz con dos hijos
    if (auxd != antesd){
      antesd->setLeft(auxd->getRight());
      auxd->setRight(antesd);
    }
    auxd->setLeft(aux->getLeft());
    delete aux;

    setRoot(auxd); // Nueva raiz 
    return auxd;
  }
  else{// el nodo que borro es cualquiera
    if(auxd == antesd)// el sustituto es inmediato derecho del que borro
      auxd->setLeft(aux->getLeft());
    else{
      antesd->setLeft(auxd->getRight());
      auxd->setLeft(aux->getLeft());
      auxd->setRight(aux->getRight());
    }
    if(antes->getRight() == aux) // el nodo que borro es hijo derecho
      antes->setRight(auxd);
    else
      antes->setLeft(auxd); // el que borro es hijo izquierdo
    delete aux;
    return antes;
  }
}

NodeABB* TreeABB::removed_a(NodeABB* antes, NodeABB* aux){
  /* 
  Función que borra el nodo si tiene un una sola rama.
  Input: Un objeto tipo Node [antes]
           Un objeto tipo Node [aux (el que se borra)]
  Output: Objeto tipo Node [padre del nodo que se borro]
  */
  if (aux == root){ // Cuando su padre es la raiz 
    if(root->getLeft() == nullptr){
      root = root->getRight();
    }
    else{
      root = root->getLeft();
    }

    delete aux;
    return root;
  }
  else{
    NodeABB *hijo; // el que borro tiene hijo der o izq
    if (aux->getRight() == nullptr){
      hijo = aux->getLeft();
    }
    else{
      hijo = aux->getRight();
    }

    if(antes->getRight() == aux){ // el que borro es hijo izq o der
      antes->setRight(hijo);
    }
    else{   // ¿Este es NECESARIO?
      antes->setLeft(hijo);
    }
    delete aux;
    return antes;
  }
}

