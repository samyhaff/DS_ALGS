open Stack

type lexeme = Number of float
           | Binary_op of (float-> float -> float)
           | Unary_op of (float -> float);;

let eval lst =
    let stack = create () in
    let rec aux = function
        | [] -> pop stack
        | (Number a)::q -> push a stack; aux q
        | (Binary_op f)::q -> let a = pop stack
                              in let b = pop stack
                              in push (f a b) stack; aux q
        | (Unary_op f)::q -> let a = pop stack in push (f a) stack; aux q
    in aux lst;;

let sum = Binary_op (fun a b -> a +. b);;
let sub = Binary_op (fun a b -> a -. b);;
let mul = Binary_op (fun a b -> a *. b);;
let div = Binary_op (fun a b -> a /. b);;

let expr = [Number 1.; Number 2.; sum] in print_float (eval expr);;
