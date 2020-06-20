<h1 align="center">
    <img alt="Logo" title="Assembler" src="images/Assembler.svg" width="360px" />
</h1>

<p align="center">
  <a href="#-projeto">Projeto</a>
  &nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href="#-exemplos">Exemplos</a>
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

## ✦ Exemplo de Entrada/Saída

- Exemplo de entrada:
	<p align="justify">add $s2, $s0, $s1</p>
	<p align="justify">sll $t1, $s2, 2</p>
	<p align="justify">or $t2, $s2, $s1</p>
	<p align="justify">andi $t2, $t1, 16</p>
	<p align="justify">addi $t3, $t2, -243</p>

- Exemplo de saída:
	<p align="justify">00000010000100011001000000100000</p>
	<p align="justify">00000000000100100100100010000000</p>
	<p align="justify">00000010010100010101000000100101</p>
	<p align="justify">00110001001010100000000000010000</p>
	<p align="justify">00100001010010111111111100001101</p>

---

<p align="justify">O projeto foi desenvolvido, para fins didáticos, durante a disciplina de Sistemas Embarcados do curso de Bacharelado em Ciência da Computação da UFV – Campus Florestal</p>
