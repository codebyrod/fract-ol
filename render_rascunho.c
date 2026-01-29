/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosousa- <rosousa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 21:57:46 by rosousa-          #+#    #+#             */
/*   Updated: 2026/01/26 22:17:21 by rosousa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double conv_pix_to_dec(double axis, double new_max, double new_min, double old_max, double old_min)
{
	double	result;
	
	//axis = o número que queremos converter
	//new_min = início da nova escala (onde começa o fractal)
	//new_max = fim da nova escala (onde começa o fractal)
	//old_min = início da antiga escala (onde começa o fractal)
	//old_max = fim da antiga escala (onde começa o fractal)
	
	// 1. Onde estou na escala antiga? (De 0 a 800)
    // Subtraímos o minimo antigo para "zerar" a posição
	double posicao_na_escala = axis - old_min;
	
	// 2. Qual o tamanho total da escala antiga? (800 - 0 = 800)
    double tamanho_antigo = old_max - old_min;
    
    // 3. Qual a minha porcentagem? (Ex: pixel 400 de 800 é 0.5 ou 50%)
    double porcentagem = posicao_na_escala / tamanho_antigo;

    // 4. Qual o tamanho da escala nova? (De -2 a +2, o tamanho é 4)
    double tamanho_novo = new_max - new_min;

    // 5. Aplica a porcentagem no tamanho novo e soma o início novo.
    // Se era 50%, agora é 50% de 4 (que é 2), mais o inicio (-2).
    // Resultado: 0.0
    return (new_min + (porcentagem * tamanho_novo));
	
}