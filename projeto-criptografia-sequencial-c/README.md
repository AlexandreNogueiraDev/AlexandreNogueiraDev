# Criptografia Sequencial em C

Projeto desenvolvido em linguagem C para aplicar conceitos de programação, matemática e criptografia simples, utilizando a Cifra de César combinada com sequências numéricas.

## 📌 Sobre o projeto

O programa permite criptografar e descriptografar palavras utilizando um valor de deslocamento (`SHIFT`) e uma sequência matemática escolhida pelo usuário.

A cada letra da palavra, o programa aplica o deslocamento fixo e o valor correspondente da sequência selecionada, produzindo um resultado que varia conforme os parâmetros informados.

O projeto foi desenvolvido como parte de uma atividade acadêmica de Algoritmo e Pensamento Computacional.

## ⚙️ Funcionalidades

- Criptografia de palavras.
- Descriptografia de palavras.
- Aplicação da Cifra de César combinada com sequências matemáticas.
- Escolha entre quatro tipos de sequências.
- Validação das entradas do usuário.
- Tratamento de entradas numéricas inválidas.
- Registro dos resultados em um arquivo de texto.
- Menu interativo para realizar novas operações.

## 🔢 Sequências matemáticas

O programa disponibiliza quatro opções:

| Opção | Sequência | Regra utilizada |
|---|---|---|
| 1 | Progressão Aritmética (PA) | Começa em 5 e aumenta de 3 em 3. |
| 2 | Progressão Geométrica (PG) | Começa em 2 e multiplica cada termo por 2. |
| 3 | Fibonacci | Começa em 1, 1 e soma os dois termos anteriores. |
| 4 | Números primos | Gera números primos a partir de 2. |

## 🔐 Como funciona a criptografia

O programa combina duas etapas de deslocamento:

1. Aplica o valor fixo informado pelo usuário (`SHIFT`).
2. Soma ao deslocamento o valor correspondente à sequência matemática.

A fórmula utilizada é:

`deslocamento_total = SHIFT + sequência[i]`

O deslocamento é aplicado às letras do alfabeto, considerando a volta de Z para A quando necessário.

Na descriptografia, o programa realiza a operação inversa para recuperar a palavra original.

## 🛠️ Tecnologias utilizadas

- Linguagem C
- Biblioteca padrão da linguagem C
- Manipulação de arquivos
- Ponteiros e alocação dinâmica de memória
- Sequências matemáticas e operações com caracteres

## ▶️ Como executar

### Pré-requisitos

É necessário ter um compilador C instalado, como o GCC.

### Compilação

No terminal, dentro da pasta do projeto, execute:

```bash
gcc criptografia.c -o criptografia
```

### Execução

No Windows:

```bash
.\criptografia.exe
```

No Linux:

```bash
./criptografia
```

Após iniciar o programa, siga as opções do menu para escolher a operação, informar a palavra, definir o `SHIFT` e selecionar a sequência matemática.

## 📄 Arquivo de resultados

O programa registra as execuções no arquivo:

`resultado_criptografia.txt`

O arquivo é criado ou atualizado pelo programa conforme as operações realizadas, mantendo o histórico dos resultados registrados.

## 🎯 Objetivos de aprendizagem

- Praticar lógica de programação em C.
- Aplicar progressões e sequências numéricas em um algoritmo.
- Compreender operações de deslocamento de caracteres.
- Trabalhar com funções, ponteiros e alocação dinâmica de memória.
- Manipular arquivos para registrar resultados.
- Implementar validação de dados e tratamento de entradas inválidas.

## ⚠️ Observação

Este projeto tem finalidade educacional. A combinação da Cifra de César com sequências matemáticas demonstra conceitos básicos de criptografia, mas não deve ser utilizada para proteger informações sensíveis em sistemas reais.

## 👨‍💻 Autor

Desenvolvido como projeto acadêmico em linguagem C.
