# Autômato com Pilha (AP / PDA)

Simulador de Autômato com Pilha implementado em C++, desenvolvido para reconhecer a linguagem:

$$L = \{ a^n b^n \mid n \geq 1 \}$$

---

## Definição Formal

Um Autômato com Pilha é definido pela 7-tupla:

$$AP = (Q,\ \Sigma,\ \Gamma,\ \delta,\ q_0,\ Z_0,\ F)$$

| Componente | Descrição | Valor |
|---|---|---|
| $Q$ | Conjunto de estados | `{q0, q1}` |
| $\Sigma$ | Alfabeto de entrada | `{a, b}` |
| $\Gamma$ | Alfabeto da pilha | `{A, Z}` |
| $\delta$ | Função de transição | (ver tabela abaixo) |
| $q_0$ | Estado inicial | `q0` |
| $Z_0$ | Símbolo inicial da pilha | `Z` |
| $F$ | Estados de aceitação | `{q1}` |

---

## Função de Transição δ

| Estado atual | Entrada | Topo da pilha | Próximo estado | Ação na pilha |
|---|---|---|---|---|
| `q0` | `a` | `Z` | `q0` | empilha `A` |
| `q0` | `a` | `A` | `q0` | empilha `A` |
| `q0` | `b` | `A` | `q1` | desempilha |
| `q1` | `b` | `A` | `q1` | desempilha |
| `q1` | — | `Z` | aceita | — |

**Aceitação:** por estado final com a entrada totalmente consumida e a pilha contendo apenas $Z_0$.

---

## Como Compilar

> **Pré-requisito:** compilador g++ (via [MSYS2](https://www.msys2.org/) no Windows).

```cmd
cd C:\Users\pdi05\Desktop\pilha
g++ main.cpp -o automato.exe
```
---

## Como Executar

```cmd
automato.exe
```

O programa solicitará uma palavra e informará se ela é **aceita** ou **rejeitada**.

---

## Exemplos

| Entrada | Resultado | Motivo |
|---|---|---|
| `ab` | ACEITA | $a^1 b^1$ |
| `aabb` | ACEITA | $a^2 b^2$ |
| `aaabbb` | ACEITA | $a^3 b^3$ |
| `aab` | REJEITADA | 2 a's e 1 b |
| `abb` | REJEITADA | 1 a e 2 b's |
| `ba` | REJEITADA | ordem errada |
| `abc` | REJEITADA | símbolo inválido |
| `aaa` | REJEITADA | sem b's |

---

## Funcionamento (passo a passo)

**Entrada:** `aabb`

| Passo | Símbolo lido | Estado | Pilha (topo → base) |
|---|---|---|---|
| início | — | `q0` | `Z` |
| 1 | `a` | `q0` | `A Z` |
| 2 | `a` | `q0` | `A A Z` |
| 3 | `b` | `q1` | `A Z` |
| 4 | `b` | `q1` | `Z` |
| fim | — | `q1` | `Z` → **ACEITA** |

---

## Estrutura do Projeto

```
pilha/
├── main.cpp       # Implementação do autômato com pilha
├── automato.exe   # Executável gerado após compilação
└── README.md      # Este arquivo
```

---

## Linguagem Reconhecida

A linguagem $L = \{ a^n b^n \mid n \geq 1 \}$ é um exemplo clássico de linguagem **livre de contexto** que **não é regular**. Isso prova que os Autômatos com Pilha são mais poderosos que os Autômatos Finitos, pois conseguem "contar" e relacionar a quantidade de símbolos em diferentes partes da palavra.
