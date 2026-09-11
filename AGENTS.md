# ODTE

## ¿Qué es?

Orquestador de Documentos Tributarios Electrónicos. Motor C++ que procesa DTEs y se comunica con el SII de Chile.

## Arquitectura

```
Contratos de entrada (FlatBuffer/JSON)
    → Traductores (Contract → Domain)
        → Domain Model (modelos C++)
            → Traductor de salida (Domain → XML)
                → Motor (validación, firma, envío SII)
```

El motor central no sabe cómo llegó la petición. Solo procesa DTEs.

## ¿Quién dirige?

Un Ingeniero (Civil Industrial + Informática). Licenciado en Ciencias de la Ingeniería.
Trabaja por conversación: primero te cuenta el problema, y cuando tienes la visión clara, te pide que lo resuelvas.

## ¿Cómo trabajas?

- Respuestas directas y concisas. No monólogos.
- Cambios quirúrgicos. No agregues nada que no se te pidió.
- La arquitectura la define el Ing., no tú.
- Si necesitas saber algo, busca. No preguntes dónde está lo que puedes encontrar.
- Si necesitas dirección, pregunta al Ing. antes de avanzar.
- No sobrepienses. Si la pregunta es simple, respóndela simple.

## Reglas duras

- Commit con descripción completa de lo que hiciste y por qué.
- PROHIBIDO: git stash, git reset, git clean, force push, o cualquier comando destructivo.
- Trabaja sin afectar el trabajo de otros agentes en paralelo.
- No crees archivos de más de 100 líneas.
- Si tienes duda, pregunta. No asumas.

## Sobre el Ing.

- No te va a responder preguntas de implementación.
- No te va a decir si ya existe una función creada para algo.
- Él orquesta. Tú ejecutas.
- Si necesitas orientación técnica, búscala en el código o en documentación, no en él.

## Al terminar una tarea

Reporta al Ing. qué hiciste y por qué. Si preguntó algo, respóndele directo. No generes documentación extra ni archivos adicionales a menos que se te pida.

## Specs del SII

Los XSDs del SII están en `schemas/`. Son la fuente de verdad para el Domain Model.
Cada XSD define la estructura XML que el SII espera recibir o devolver.

## Stack

- C++17
- CMake
- GTest (tests)
- Boost.JSON (parser JSON)
- FlatBuffers (serialización binaria)
- clang-format / clang-tidy (linting)

## Convenciones de Nombre

**Todo el código debe estar en inglés.** El domain model debe ser autoexplicativo y claro para cualquier desarrollador.

### Reglas de Nombre

- **Enums**: `PascalCase` con valores descriptivos
  - ✅ `PaymentMethod::CREDIT_CARD`
  - ❌ `MedioPago::TC`

- **Value Objects**: `PascalCase` con intención clara
  - ✅ `BusinessName`, `DocumentType`, `PaymentMethod`
  - ❌ `RazonSocial`, `TipoDTE`, `MedioPago`

- **Structs**: `PascalCase` con nombres descriptivos
  - ✅ `ElectronicDocument`, `DocumentHeader`, `LineItem`
  - ❌ `DTE`, `Encabezado`, `Detalle`

- **Métodos**: `snake_case` con nombre que inicia con verbo
  - ✅ `is_valid()`, `to_string()`, `get_value()`
  - ❌ `valid()`, `valor()`

### Ejemplo

```cpp
// Bueno: Claro, autoexplicativo
enum class PaymentMethod : std::uint8_t {
  CHECK = 0,
  PROMISSORY_NOTE = 1,
  CASH = 2,
  CREDIT_CARD = 4,
};

// Malo: Críptico, requiere traducción
enum class MedioPago : std::uint8_t {
  CH = 0,
  LT = 1,
  EF = 2,
  TC = 4,
};
```
