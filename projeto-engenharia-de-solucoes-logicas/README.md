# 🚦 Sistema de Semáforo para Cidades Inteligentes

## 📝 Descrição do Projeto
Este projeto consiste em um algoritmo de controle inteligente para semáforos urbanos, visando otimizar o fluxo de tráfego em "Cidades Inteligentes". O sistema ajusta dinamicamente o **Tempo de Espera (TE)** do sinal verde com base em sensores de presença de veículos, pedestres e no horário do dia.

O algoritmo processa dados em tempo real para priorizar vias congestionadas ou horários de pico, garantindo também a segurança dos pedestres e respeitando limites mínimos e máximos de tempo para evitar travamentos no fluxo.


## ⚙️ Funcionamento do Algoritmo
O sistema utiliza uma lógica de ajuste incremental baseada nas seguintes condições:
* [cite_start]**Validação de Dados:** Verifica se os valores de sensores (Veículos, Pedestres e Horas) são válidos (ex: Horas entre 0 e 23)[cite: 57, 59].
* [cite_start]**Prioridade por Horário:** Adiciona tempo extra se for horário de pico (ex: ≥ 18h)[cite: 62, 63].
* [cite_start]**Densidade de Veículos:** Aumenta o tempo do sinal verde se o número de veículos for alto (≥ 40)[cite: 65, 66].
* [cite_start]**Fluxo de Pedestres:** Reduz o tempo de espera se houver alta concentração de pedestres (≥ 75) para agilizar a travessia[cite: 21, 23, 68].
* [cite_start]**Limites de Segurança:** Garante que o tempo final esteja sempre entre um intervalo seguro (ex: entre 5 e 120 segundos)[cite: 74, 75, 77, 78].

## 🚀 Tecnologias e Estruturas
* [cite_start]**Linguagem:** Pseudocódigo (Portugal) / Lógica de Programação[cite: 48].
* [cite_start]**Estruturas:** Condicionais compostas (`SE/ENTÃO/SENÃO`) e Laços de repetição (`ENQUANTO`)[cite: 57, 60, 80].
* [cite_start]**Entradas (Sensores):** * `VC`: Sensor de Veículos[cite: 5, 54].
    * [cite_start]`PO`: Sensor de Pedestres[cite: 7, 56].
    * [cite_start]`HR`: Obtenção de Hora atual[cite: 5, 55].

## 📊 Regras de Negócio (Lógica de Ajuste)
| Condição | Ação no Tempo (TE) |
| :--- | :--- |
| Dados Inválidos | [cite_start]Exibe mensagem de "ERRO" [cite: 59] |
| Horário ≥ 18h | [cite_start]TE = TE + 20 [cite: 63] |
| Veículos ≥ 40 | [cite_start]TE = TE + 20 [cite: 66] |
| Pedestres ≥ 75 | [cite_start]TE = TE - 20 [cite: 68] |
| TE final < 5s | [cite_start]Ajusta para 5s [cite: 75] |
| TE final > 120s | [cite_start]Ajusta para 120s [cite: 78] |

## 🔧 Como Executar
Como o projeto está representado em pseudocódigo:
1.  Abra um interpretador de algoritmos (como o **Visualg**).
2.  [cite_start]Copie a estrutura contida no arquivo `CidadeInteligentes.pdf` (Parte 1 e 2)[cite: 47, 73].
3.  Execute o passo a passo para simular as entradas dos sensores.

---
[Voltar ao início](https://github.com/portfolio-alexandre-almeida-de-jesus-nogueira/portfolio-alexandre-almeida-de-jesus-nogueira)
