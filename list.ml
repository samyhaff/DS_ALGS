(* list implementation *)

type 'a list = Nil | Cell of 'a * ('a list);;

let create t q = Cell(t, q);;

let head = function
    | Nil -> failwith "empty list"
    | Cell(h, t) -> t;;

let tail = function
    | Nil -> failwith "empty list"
    | Cell(h, t) -> t;;

(* functions on the buit in type *)

let rec list_length = function
    | [] -> 0
    | _::t -> 1 + list_length t;;

let rec last = function
    | [] -> failwith "empty list"
    | h::[] -> h
    | _::t -> last t;;

let rec member x l = match l with
| [] -> false
| h::_ when h = x -> true
| _::q -> member x q;;

let rec nth n l = match l with
| [] -> raise Not_found
| h::_ when n = 1 -> h
| _::t -> nth (n - 1) t;;

let rec concat l1 l2 = match l1 with
| [] -> l2
| h::t -> h::(concat t l2);;

let rec map f l = match l with
| [] -> []
| h::t -> (f h)::(map f t);;
