# 🛡️ Algoritmo de Auditoria de Dados de Vendas

## 📝 Descrição do Projeto
Este projeto consiste numa ferramenta de auditoria automatizada para validar transações de vendas. O objetivo principal é identificar inconsistências estatísticas (*outliers*) e garantir que as operações financeiras estejam dentro dos parâmetros de segurança estabelecidos pela organização.

Desenvolvido como parte da disciplina de **Lógica de Programação / Auditoria de Sistemas**, o script processa entradas de vendas, calcula médias e aplica regras de negócio para disparar alertas de revisão manual ou quarentena do sistema.

## ⚙️ Funcionalidades Principais
* **Detecção de Anomalias:** Identifica se uma venda é desproporcional (5x maior) em relação à média das demais.
* **Controle de Limite:** Monitora vendas que ultrapassam o `LIMITE_SEGURANCA` (padrão inicial: 10.000).
* **Gestão de Segurança:** Permite a atualização dinâmica do limite de segurança caso uma venda alta seja confirmada pelo auditor como legítima.
* **Modo de Quarentena:** Bloqueia simbolicamente o sistema caso a média geral das operações ultrapasse o teto de segurança.

## 🚀 Tecnologias Utilizadas
* **Linguagem:** Python 3.x
* **Ambiente:** Google Colab / Terminal Python
* **Conceitos Aplicados:** Variáveis globais, estruturas condicionais, tratamento de exceções (`try/except`) e manipulação de tipos de dados (float/string).

## 📊 Regras de Negócio
O algoritmo segue o seguinte fluxo lógico:
1. **Revisão Manual:** Ativada se uma venda for 5 vezes superior à média das outras duas vendas.
2. **Validação de Limite:** Se uma venda ultrapassar o limite (10.000), o sistema solicita intervenção humana para validar a operação e permite redefinir o limite global.
3. **Quarentena:** Se a média das três vendas for superior ao Limite de Segurança, o sistema entra em estado de alerta.

## 🔧 Como Executar
1. Certifique-se de ter o Python 3 instalado na sua máquina.
2. Clone este repositório ou descarregue o ficheiro `projeto_algoritmo_de_auditoria_de_dados.py`.
3. Execute o script através do terminal:
   ```bash
   python projeto_algoritmo_de_auditoria_de_dados.py
