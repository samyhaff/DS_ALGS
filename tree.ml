open Queue

(* tree implementations *)

(*
type ('a, 'b) tree =
    | Leaf of 'a
    | Node of 'b * ('a, 'b)  tree * ('a, 'b) tree;;

type 'a tree = Nil | Node of 'a * ('a tree list);;
*)

type 'a tree =
    | Nil
    | Node of int * int tree * int tree;;

let rec nb_nodes = function
    | Nil -> 0
    | Node(_, l, r) -> 1 + nb_nodes(l) + nb_nodes(r);;

let rec height = function
    | Nil -> -1
    | Node(_, l, r) -> 1 + max (height l) (height r);;

let rec preorder = function
    | Nil -> ()
    | Node(n, l, r) -> print_int n; preorder l; preorder r;;

let rec postorder = function
    | Nil -> ()
    | Node(n, l, r) -> postorder l; postorder r; print_int n;;

let rec inorder = function
    | Nil -> ()
    | Node(n, l, r) -> postorder l; print_int n; postorder r;;

let rec breadth_first tree =
    let queue = create () in
    push tree queue;
    let rec aux () = match (pop queue) with
    | Nil -> ()
    | Node(n, l, r) -> print_int n;
                       push l queue;
                       push r queue;
                       aux ()
    in aux();;

let tree = Node(1, Node(2, Node(4, Nil, Nil), Node(5, Nil, Nil)), Node(3, Nil, Nil))
in breadth_first tree;;

(* BST *)

let rec insert t x = match t with
    | Nil -> Node(x, Nil, Nil)
    | Node(y, l, r) when y = x -> t
    | Node(y, l, r) when y < x -> Node(y, l, insert r x)
    | Node(y, l, r) -> Node(y, insert l x, r);;

let rec create = function
    [] -> Nil
    | h::t -> insert (create t) h;;

let rec search t x = match t with
    | Nil -> false
    | Node(y, _, _) when x = y -> true
    | Node(y, _, _) when x = y -> true
    | Node(y, l, r) when x < y -> search l x
    | Node(y, l, r) -> search r x;;

let rec merge l r = match l, r with
    | Nil, _ -> r
    | _, Nil -> l
    |Node(x1, l1, r1), Node(x2, l2, r2) -> Node(x1, l1, Node(x2, merge l2 r1, r2));;

let rec delete t x = match t with
    | Nil -> failwith "empty tree"
    | Node(y, l, r) when y = x -> merge l r
    | Node(y, l, r) when y < x -> Node(y, l, delete r x)
    | Node(y, l, r)  -> Node(y, delete l x, r);;
