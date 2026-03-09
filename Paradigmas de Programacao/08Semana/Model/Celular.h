/**
 * Project Untitled
 */


#ifndef _CELULAR_H
#define _CELULAR_H

#include "ProdutoEletronico.h"


class Celular: public ProdutoEletronico {
public: 
    
void Celular();
    
/**
 * @param marca
 */
void Celular(String marca);
    
/**
 * @param peso
 */
void Celular(float peso);
    
/**
 * @param nomeFabricante
 * @param peso
 * @param marca
 */
void Celular(String nomeFabricante, float peso, String marca);
    
void vender();
    
void acionarGarantia();
    
void ligar_desligar();
};

#endif //_CELULAR_H