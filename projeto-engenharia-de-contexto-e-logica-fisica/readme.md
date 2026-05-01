# 🌍 Monitorização Ambiental e Simulação de Evacuação

## 📝 Descrição do Projeto
Este projeto integra dois sistemas lógicos desenvolvidos em Python: uma ferramenta de análise de indicadores ambientais urbanos e um simulador de navegação espacial para protocolos de evacuação.

## ⚙️ Funcionalidades Principais

### 1. Análise Ambiental de Locais Urbanos (`analiseAmbiental`)
O sistema processa dados reais de diferentes zonas (Guaianases, Itaquera, Tatuapé) em diferentes horários para calcular o bem-estar dos cidadãos:
* [cite_start]**Classificação IQA:** Categoriza a qualidade do ar de "Boa" até "Perigosa" usando estruturas de `match/case`[cite: 2].
* [cite_start]**Cálculo de Nota de Conforto:** Algoritmo que aplica penalizações baseadas em desvios da temperatura ideal (22°C), humidade ideal (50%) e níveis de poluição[cite: 2].

### 2. Navegação e Evacuação Espacial
Um motor de simulação onde um "agente" deve atravessar uma planta de edifício sob restrições:
* [cite_start]**Gestão de Energia:** Cada movimento consome energia; se chegar a zero, a evacuação falha[cite: 2].
* [cite_start]**Interação com Objetos:** O agente interage com portas trancadas, procura chaves e recolhe extintores[cite: 2].
* [cite_start]**Obstáculos Dinâmicos:** Lógica para lidar com escadas estreitas e caminhos bloqueados[cite: 2].

## 🚀 Tecnologias Utilizadas
* **Linguagem:** Python 3.10+
* [cite_start]**Estruturas de Controlo:** `while True`, `match/case` (Python 3.10), e iteração dupla com `enumerate`[cite: 2].
* [cite_start]**Lógica de Inventário:** Uso de dicionários para monitorizar estados (chave, energia, itens)[cite: 2].

[Voltar ao início](https://github.com/portfolio-alexandre-almeida-de-jesus-nogueira/portfolio-alexandre-almeida-de-jesus-nogueira)
