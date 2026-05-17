# propia Pilas y Colas (modo LEGO) POO
# Pila & Cola en C++

Implementación de estructuras de datos Pila (LIFO) y Cola (FIFO) usando listas enlazadas y herencia en C++.

## Estructura

- `Lista` — clase padre con el nodo base y `mostrar()`
- `Pila` — hereda de `Lista`; métodos: `push_it()`, `pop()`
- `Cola` — hereda de `Lista`; métodos: `push()`, `pull()`

## Métodos

| Clase | Método | Qué hace |
|-------|--------|----------|
| Pila | `push_it(val)` | Inserta al tope |
| Pila | `pop()` | Elimina del tope |
| Cola | `push(val)` | Inserta al final |
| Cola | `pull()` | Elimina del frente |

## Uso

```cpp
Pila pila;
pila.push_it(10);
pila.mostrar();
pila.pop();

Cola cola;
cola.push(5);
cola.mostrar();
cola.pull();
```

## Compilar

```bash
g++ main.cpp -o programa
./programa
```

