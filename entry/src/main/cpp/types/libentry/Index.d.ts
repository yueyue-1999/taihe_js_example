export const sub: (a: number, b: number) => number;

export const split_str: (pstr: string, n: number) => Array<string>;

export const get_rgb: (n: number) => RGB;

export class RGB {
  constructor();
  r: number;
  g: number;
  b: number;
}