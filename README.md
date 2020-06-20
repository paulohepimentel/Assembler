<h1 align="center">
    <img alt="Logo" title="NotiFlame" src="images/NotiFlame.svg" width="360px" />
</h1>

<p align="center">
  <a href="#-projeto">Projeto</a>
  &nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#-resultado">Resultado</a>
</p>

<p align="center">
    <img alt="Logo" title="Assembler" src="images/Assembler.svg" width="100%"/>
</p>

## ✦ Projeto
<p align="justify">O trabalho consiste na implementação de uma versão simplificada de um montador MIPS. O montador ou assembler é um programa que cria o código objeto traduzindo as instruções da linguagem de montagem (assembly) para código de máquina.</p>

<p align="justify">Instruções implementadas:</p>

- ADD;
- SUB;
- AND;
- OR;
- NOR;
- ADDI;
- ANDI;
- ORI;
- SLL;
- SRL.

#### Exemplo de Entrada/Saída

- Exemplo de entrada:
	
	add $s2, $s0, $s1
	sll $t1, $s2, 2
	or $t2, $s2, $s1
	andi $t2, $t1, 16
	addi $t3, $t2, -243

- Exemplo de saída:
	00000010000100011001000000100000
	00000000000100100100100010000000
	00000010010100010101000000100101
	00110001001010100000000000010000
	00100001010010111111111100001101

---

<p align="justify">O projeto foi desenvolvido, para fins didáticos, durante a disciplina de Sistemas Embarcados do curso de Bacharelado em Ciência da Computação da UFV – Campus Florestal</p>
