/**
 * Project Untitled
 */


#ifndef _TELEVISAO_H
#define _TELEVISAO_H

#include "ProdutoEletronico.h"


class Televisao: public ProdutoEletronico {
public: 
    
void Televisao();
    
/**
 * @param marca
 */
void Televisao(String marca);
    
/**
 * @param tamanho
 */
void Televisao(float tamanho);
    
/**
 * @param nomeFabricante
 * @param peso
 * @param marca
 * @param tamanho
 */
void Televisao(String nomeFabricante, float peso, String marca, float tamanho);
    
/**
 * @param tamanho
 */
void setTamanho(float tamanho);
    
float getTamanho();
    
void vender();
    
void acionarGarantia();
    
void ligar_desligar();
    
String toString();
    
/**
 * @param t
 */
int compareTo(Televisao t);
private: 
    float tamanho;
};

#endif //_TELEVISAO_H