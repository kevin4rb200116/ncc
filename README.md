# Nautilus Compiler (NCC)

Un lenguaje de programación compilado y de tipos estáticos que combina la compatibilidad con C y todas sus interfaces, con la facilidad y simplicidad de Python.

![License](https://img.shields.io/badge/license-GPL3-blue.svg)
![Build System](https://img.shields.io/badge/build-meson-green.svg)
![LLVM](https://img.shields.io/badge/backend-LLVM-orange.svg)

## Tabla de contenidos

- [Características](#características)
- [Arquitectura](#arquitectura)
- [Estructura del proyecto](#estructura-del-proyecto)
- [Dependencias](#dependencias)
- [Instalación](#instalación)
- [Uso](#uso)
- [Desarrollo](#desarrollo)
- [Roadmap](#roadmap)
- [Contribuir](#contribuir)
- [Licencia](#licencia)

## Características

- ✅ **Compatibilidad con C**: Interfaz completa con bibliotecas y código C existente
- ✅ **Tipos estáticos**: Sistema de tipos robusto para mayor seguridad
- ✅ **Sintaxis simple**: Inspirada en Python para mayor legibilidad
- ✅ **Compilación nativa**: Genera código optimizado usando LLVM
- ✅ **Arquitectura modular**: Diseño en capas para facilitar el mantenimiento

## Arquitectura

Nautilus Compiler sigue una arquitectura en capas, donde cada módulo depende únicamente de las capas anteriores:

```
┌─────────────────┐
│     irgen       │  ← Generación de IR (LLVM)
├─────────────────┤
│     parser      │  ← Análisis sintáctico (Bison)
├─────────────────┤
│     lexer       │  ← Análisis léxico (Flex)
└─────────────────┘
```

### Módulos

1. **Lexer**: Análisis léxico usando Flex
   - Convierte código fuente en tokens
   - No tiene dependencias externas del compilador

2. **Parser**: Análisis sintáctico usando Bison
   - Construye el AST (Abstract Syntax Tree)
   - Depende del módulo lexer

3. **IRGen**: Generación de representación intermedia
   - Convierte el AST a LLVM IR
   - Depende del módulo parser

4. **CodeGen** *(planeado)*: Generación de código objeto
   - Compilación final a código máquina
   - Optimizaciones de backend

## Estructura del proyecto

```
ncc/
├── meson.build              # Configuración principal de construcción
├── lexer/                   # Módulo de análisis léxico
│   ├── src/                 # Código fuente del lexer
│   ├── test/                # Pruebas del lexer
│   └── meson.build          # Configuración del módulo (genera libnlex.a)
├── parser/                  # Módulo de análisis sintáctico
│   ├── src/                 # Código fuente del parser
│   ├── test/                # Pruebas del parser
│   └── meson.build          # Configuración del módulo (genera libnparse.a)
├── irgen/                   # Módulo de generación de IR
│   ├── src/                 # Código fuente del generador IR
│   ├── test/                # Pruebas del generador IR
│   └── meson.build          # Configuración del módulo (genera libnirgen.a)
└── examples/                # Ejemplos de código Nautilus
```

### Convenciones del proyecto

- Cada módulo genera una biblioteca estática (`lib<modulo>.a`)
- Los módulos de capas inferiores incluyen ejecutables de prueba
- El código está ampliamente comentado para facilitar la comprensión
- Las dependencias siguen un orden estricto: lexer → parser → irgen

## Dependencias

### Herramientas de construcción
- **Meson**: Sistema de construcción principal
- **Ninja**: Backend de construcción (recomendado)

### Herramientas de análisis
- **Flex**: Generador de analizadores léxicos
- **Bison**: Generador de analizadores sintácticos

### Backend de compilación
- **LLVM**: Framework de compilación y optimización
  - Generación de representación intermedia
  - Optimizaciones de código
  - Generación de código objeto

### Instalación de dependencias

#### Ubuntu/Debian
```bash
sudo apt update
sudo apt install meson ninja-build flex bison llvm-dev
```

#### Fedora/RHEL
```bash
sudo dnf install meson ninja-build flex bison llvm-devel
```

#### macOS
```bash
brew install meson ninja flex bison llvm
```

## Instalación

1. **Clonar el repositorio**
```bash
git clone https://github.com/kevin4rb200116/ncc.git
cd ncc
```

2. **Configurar el proyecto**
```bash
meson setup builddir
```

3. **Compilar**
```bash
cd builddir
meson compile
```

4. **Ejecutar pruebas**
```bash
meson test
```

## Uso

### Compilar un programa Nautilus

```bash
# Compilar archivo fuente
./ncc programa.nt -o programa

# Ejecutar
./programa
```

### Ejemplo de código Nautilus

```python
# Sintaxis similar a Python, pero con tipos estáticos
def fibonacci(n: int) -> int:
    if n <= 1:
        return n
    return fibonacci(n-1) + fibonacci(n-2)

# Compatibilidad con C
extern "C" {
    int printf(const char* format, ...);
}

def main() -> int:
    result = fibonacci(10)
    printf("Fibonacci(10) = %d\n", result)
    return 0
```

## Desarrollo

### Probar módulos individuales

```bash
# Probar solo el lexer
cd builddir
./lexer/nlex < ../examples/ejemplo.nt

# Probar solo el parser
./parser/nparse < ../examples/ejemplo.nt

# Probar la generación de IR
./irgen/nirgen < ../examples/ejemplo.nt
```

### Estructura de desarrollo

1. **Lexer**: Desarrollar nuevos tokens en `lexer/src/`
2. **Parser**: Extender gramática en `parser/src/`
3. **IRGen**: Agregar generación de IR en `irgen/src/`
4. **Tests**: Agregar pruebas en `<modulo>/test/`

## Roadmap

### Versión actual (v0.1)
- [x] Análisis léxico básico
- [x] Análisis sintáctico fundamental
- [x] Generación básica de LLVM IR
- [x] Sistema de construcción con Meson

### Próximas versiones

#### v0.2
- [ ] Módulo de generación de código objeto
- [ ] Optimizaciones básicas
- [ ] Mejores mensajes de error

#### v0.3
- [ ] Sistema de tipos más robusto
- [ ] Soporte para estructuras y clases
- [ ] Interoperabilidad C completa

#### Futuro
- [ ] Just-In-Time Compiler (JIT)
- [ ] Modo intérprete
- [ ] Herramientas de depuración
- [ ] Package manager

## Contribuir

¡Las contribuciones son bienvenidas! Por favor:

1. **Fork** el proyecto
2. **Crea una rama** para tu funcionalidad (`git checkout -b feature/nueva-funcionalidad`)
3. **Documenta** tu código siguiendo las convenciones del proyecto
4. **Agrega pruebas** para la nueva funcionalidad
5. **Commit** tus cambios (`git commit -m 'Agregar nueva funcionalidad'`)
6. **Push** a la rama (`git push origin feature/nueva-funcionalidad`)
7. **Abre un Pull Request**

### Guías de contribución

- El código debe estar bien comentado
- Seguir la arquitectura en capas existente
- Agregar pruebas para nueva funcionalidad
- Mantener compatibilidad con versiones anteriores

## Licencia

Este proyecto está bajo la Licencia GNU GENERAL PUBLIC LICENSE - ver el archivo [LICENSE](LICENSE) para más detalles.

## Contacto

- **Autor**: Kevin Rodriguez
- **Email**: kevin4rb200116@gmail.com
- **GitHub**: https://github.com/kevin4rb200116

---

*Nautilus Compiler - Donde la simplicidad de Python se encuentra con el poder de C*