# 💻 Algoritmos e Programação - UFRGS

Repositório dedicado a armazenar as atividades práticas semanais da disciplina de **Algoritmos e Programação**, desenvolvidas durante o 1º semestre do curso de Ciência da Computação na Universidade Federal do Rio Grande do Sul (UFRGS) em 2026/1.

Todas as soluções foram implementadas em linguagem **C**.

## 🗂️ Estrutura do Repositório

Para facilitar a navegação e o entendimento da evolução dos conceitos ao longo do semestre, o repositório está organizado em pastas semanais. 

Dentro de cada pasta, você encontrará:
1. **O arquivo PDF** com o enunciado e as instruções da atividade (fornecido na disciplina).
2. **Os arquivos fonte (`.c`)** contendo as soluções desenvolvidas.
3. *(Opcional)* Um pequeno `README.md` específico da semana explicando a lógica utilizada.

A estrutura de diretórios segue este formato:

```text
📦 ufrgs-algprog-c
 ┣ 📂 semana-01
 ┃ ┣ 📜 enunciado-semana-01.pdf
 ┃ ┗ 📜 exercicio.c
 ┣ 📂 semana-02
 ┃ ┣ 📜 enunciado-semana-02.pdf
 ┃ ┣ 📜 exercicio-a.c
 ┃ ┗ 📜 exercicio-b.c
 ┣ 📜 .gitignore
 ┗ 📜 README.md
```

## 🚀 Como compilar e executar

Os códigos foram escritos e testados em ambiente Linux (Pop!_OS). Para rodar qualquer um dos exercícios na sua máquina, certifique-se de ter o compilador `gcc` instalado.

1. Clone este repositório:
   ```bash
   git clone https://github.com/seu-usuario/ufrgs-algprog-c.git
   ```

2. Navegue até a pasta da semana desejada:
   ```bash
   cd ufrgs-algprog-c/semana-01
   ```

3. Compile o código desejado utilizando o `gcc`:
   ```bash
   gcc exercicio.c -o exercicio
   ```

4. Execute o programa compilado:
   ```bash
   ./exercicio
   ```

## 🧠 Conceitos Abordados

Ao longo das semanas, os seguintes tópicos foram aplicados na prática:
* Sintaxe básica de C e tipos de dados
* Estruturas condicionais (`if/else`, `switch`)
* Estruturas de repetição (`for`, `while`, `do-while`)
* Manipulação de Vetores e Matrizes
* Modularização com Funções
* Strings
* Ponteiros e Alocação Dinâmica de Memória
* Structs

---
Desenvolvido por **Iago Augusto Diotti Viana** como parte da trajetória acadêmica em Ciência da Computação.
