/**
 * Project Untitled
 */


#ifndef _SERVICO_H
#define _SERVICO_H

class Servico {
public: 
    
void Servico();
    
/**
 * @param formato
 */
void Servico(char formato);
    
/**
 * @param duracao
 */
void Servico(int duracao);
    
/**
 * @param formato
 * @param duracao
 */
void Servico(char formato, int duracao);
    
/**
 * @param formato
 */
void setFormato(char formato);
    
char getFormato();
    
/**
 * @param duracao
 */
void setDuracao(int duracao);
    
int getDuracao();
    
String mostrarFormato();
    
String toString();
    
void vender();
    
void acionarGarantia();
private: 
    char formato;
    int duracao;
};

#endif //_SERVICO_H