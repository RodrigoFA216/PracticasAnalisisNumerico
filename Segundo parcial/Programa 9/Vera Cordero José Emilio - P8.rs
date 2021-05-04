/*
 * Autor: Vera Cordero José Emilio
 *
 * Programa: Método de Gauss-Jordan
 * para obtener la matriz inversa de
 * sistemas de ecuaciones 3x3
 */

use std::io::{stdin, stdout,
    Write, Read};

fn pause() {
    let mut stdout = stdout();
    stdout.write(b"\nPresione ENTER para continuar...").unwrap();
    stdout.flush().unwrap();
    stdin().read(&mut [0]).unwrap();
    println!("");
}

// Resuelve el sistemas de ecuaciones y obtiene la matriz
// inversa por el método de Gauss-Jordan 
fn solve_gj(mut matrix: [[f64; 4]; 3]) {
	let mut inv_matrix: [[f64; 3]; 3] = [[0f64; 3]; 3];
    let k = 1.0 / matrix[0][0];
    let kf1 = matrix[1][0];
    let kf2 = matrix[2][0];

    inv_matrix[0][0] = 1f64;
    inv_matrix[1][1] = 1f64;
    inv_matrix[2][2] = 1f64;

    for i in 0..=3 {
        matrix[0][i] *= k;
        matrix[1][i] -= kf1 * matrix[0][i];
        matrix[2][i] -= kf2 * matrix[0][i];
    }

    for i in 0..=2 {
        inv_matrix[0][i] *= k;
        inv_matrix[1][i] -= kf1 * inv_matrix[0][i];
        inv_matrix[2][i] -= kf2 * inv_matrix[0][i];
    }

    let k = 1.0 / matrix[1][1];
    let kf1 = matrix[0][1];
    let kf2 = matrix[2][1];

    for i in 0..=3 {
        matrix[1][i] *= k;
        matrix[0][i] -= kf1 * matrix[1][i];
        matrix[2][i] -= kf2 * matrix[1][i];
    }

    for i in 0..=2 {
        inv_matrix[1][i] *= k;
        inv_matrix[0][i] -= kf1 * inv_matrix[1][i];
        inv_matrix[2][i] -= kf2 * inv_matrix[1][i];
    }

    let k = 1.0 / matrix[2][2];
    let kf1 = matrix[0][2];
    let kf2 = matrix[1][2];

    for i in 0..=3 {
        matrix[2][i] *= k;
        matrix[1][i] -= kf2 * matrix[2][i];
        matrix[0][i] -= kf1 * matrix[2][i];
    }

    for i in 0..=2 {
        inv_matrix[2][i] *= k;
        inv_matrix[1][i] -= kf2 * inv_matrix[2][i];
        inv_matrix[0][i] -= kf1 * inv_matrix[2][i];
    }

    println!("\nLa matriz resuelta es:");
    for i in 0..=2 {
        println!("{:.2}x₁+({:.2}x₂)+({:.2}x₃) = {:.2}", matrix[i][0],
            matrix[i][1], matrix[i][2], matrix[i][3]);
    }

    println!("\nLa matriz inversa es:");
    for i in 0..=2 {
        println!("{:.2} {:.2} {:.2}", inv_matrix[i][0],
            inv_matrix[i][1], inv_matrix[i][2]);
    }

    println!("\nLos resultados son: ");
    println!("x₁ = {:.2}\nx₂ = {:.2}\nx₃ = {:.2}", matrix[0][3],
    	matrix[1][3], matrix[2][3]);

}

fn main() {
    let mut matrix: [[f64; 4]; 3] = [[0f64; 4]; 3];
    
    /* Lectura de la matriz */
    for i in 0..=2 {
        for j in 0..=3 {
            let mut x: String = String::new();
            let mut var: String = String::from("x");

            match j {
                3 => {
                    print!("Dé el resultado de la ecuación {}: ", i+1);
                    Write::flush(&mut stdout())
                        .expect("No fue posible imprimir");

                    stdin()
                        .read_line(&mut x)
                        .expect("No fue posible leer la entrada");

                    matrix[i][j] = x
                        .trim().parse()
                        .expect("Número no válido o entrada erronea");
                },
                _ => {
                    match j {
                        0 => var = "x₁".to_string(),
                        1 => var = "x₂".to_string(),
                        2 => var = "x₃".to_string(),
                        _ => (),
                    }
                    print!("Dé el coeficiente de {} de la ecuación {}: ", var, i+1);
                    Write::flush(&mut stdout())
                        .expect("No fue posible imprimir");

                    stdin()
                        .read_line(&mut x)
                        .expect("No fue posible leer la entrada");

                    matrix[i][j] = x
                        .trim().parse()
                        .expect("Número no válido o entrada erronea");
                },
            }
        }
        println!();
    }

    print!("\x1B[2J\x1B[1;1H");

    println!("El sistema de ecuaciones es:");
    for i in 0..=2 {
        println!("{}x₁+({}x₂)+({}x₃) = {}", matrix[i][0],
            matrix[i][1], matrix[i][2], matrix[i][3]);
    }

    solve_gj(matrix);
    pause();
}
