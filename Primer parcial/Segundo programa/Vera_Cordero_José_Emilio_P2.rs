/*
* Programa: Método de bisección
*
* Autor: José Emilio Vera Cordero
* Fecha: 21/03/3021
*
*
* Formulas:
* xₘ = (xᵢ + xₛ)/2
* n = (ln(a) - ln(Ɛ))/ln(2)
* Error = |xₘ + xₘ₊₁|
*
* Ecuacion:
* f(x) = x³ + 2x² + 10x - 20
* Ɛ = 0.001
*/

/* cargo versión 1.50, rustc versión 1.50*/

/* Argumentos para compilar: cargo build */

use std::io::{stdin, stdout,
    Read, Write};

/* Función para detener el programa hasta que se presione "Enter" */
fn pause() {
    let mut stdout = stdout();
    stdout.write(b"\nPresione ENTER para continuar...").unwrap();
    stdout.flush().unwrap();
    stdin().read(&mut [0]).unwrap();
    println!("");
}

fn main() {
    /* Declaración de límite izquierdo y derecho */
    let mut xi: f64 = 1f64;
    let mut xd: f64 = 2f64;
    
    println!("La ecuacion es: \nf(x) = x³ + 2x² + 10x - 20");
    println!("  xᵢ = {}\n  xₛ = {}", xi, xd);

    /* Declaración de Epsilon (ep = Ɛ) */
    let ep: f64 = 0.001f64;
    /* Declaración y cálculo sobre el número de iteraciones a realizar */
    let n: f64 = (((xd - xi).ln() - ep.ln()) / 2f64.ln())
        .ceil();
        
    /* Imprime la tabla con formato */
    println!("\n# Iteraciones {0:>8} {1:>8} {2:>8} {3:>10} {4:>9}",
        xi="Xᵢ", xd="Xₛ", xm="Xₘ", f="f(Xₘ)", E="E");

    /* Variable auxiliar para poder calcular el error */
    let mut err_inter: f64 = 0f64;

    /* Ciclo en que se llevará a cabo el método de bisección */
    for i in 1..=n as u64 {
        /* Declaración y cálculo de xₘ */
        let xm: f64 = (xi + xd) / 2f64;
        /* Declaración y cálculo de 'ecuxm' (ecuxm es la función f(xₘ)) */
        let ecuxm: f64 = xm.powi(3)+(2f64*xm.powi(2))+(10f64*xm)-20f64;

        /* Si es el primer ciclo (i = 1) entonces no se muetra el primer error */
        if i > 1 {
            /* Cálculo del Error */
            let err: f64 = (err_inter - xm).abs();
            println!("{0:>8} {1:>14.2} {2:>8.2} {3:>8.2} {4:>10.4} {5:>10.4}%",
                    i, xi, xd, xm, ecuxm, err);
            err_inter = xm;
        } else {
            println!("{0:>8} {1:>14.2} {2:>8.2} {3:>8.2} {4:>10.4}",
                    i, xi, xd, xm, ecuxm);
            err_inter = xm;
        }

        /*
        * Condición para saber qué variable tomará el valor
        * de 'xm' (si ecum  'xd' o 'xi')
        */
        if ecuxm > 0f64 {
            xd = xm;
        } else if ecuxm < 0f64 {
            xi = xm;
        }
    }

    pause();
}
