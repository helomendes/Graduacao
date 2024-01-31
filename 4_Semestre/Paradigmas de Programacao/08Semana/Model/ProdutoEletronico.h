/**
 * Project Untitled
 */


#ifndef _PRODUTOELETRONICO_H
#define _PRODUTOELETRONICO_H

class ProdutoEletronico {
public: 
    
void ProdutoEletronico();
    
/**
 * @param marca
 */
void ProdutoEletronico(String marca);
    
/**
 * @param peso
 */
void ProdutoEletronico(flot peso);
    
/**
 * @param nomeFabricante
 * @param peso
 * @param marca
 */
void ProdutoEletronico(String nomeFabricante, float peso, String marca);
    
/**
 * @param nomeFabricante
 */
void setNomeFab(String nomeFabricante);
    
String getNomeFab();
    
/**
 * @param peso
 */
void setPeso(float peso);
    
float getPeso();
    
/**
 * @param marca
 */
void setMarca(String marca);
    
String getMarca();
    
/**
 * @param ligado
 */
void setLigado(boolean ligado);
    
boolean getLigado();
    
/**
 * @param p
 */
void ligar_desligar(ProdutoEletronico p);
    
String mostrarLigado();
    
String toString();
    
void Operation16();
protected: 
    String nomeFabricante;
    float peso;
    String marca;
    boolean ligado;
};

#endif //_PRODUTOELETRONICO_H