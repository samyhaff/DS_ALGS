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

(* heap *)

(* array of size N + 1 were array(0) = n *)

let swap t m n = let temp = t.(m) in t.(m) <- t.(n); t.(n) <- temp;;

let rec aux_ascend t n =
    if n > 1 then begin
        let m = n / 2 in
        if t.(m) < t.(n) then begin
            swap t m n;
            aux_ascend t m;
        end;
    end;;

let add t x =
    let n = t.(0) in
    t.(n+1) <- x;
    aux_ascend t (n + 1);
    t.(0) <- n + 1;;

let make_heap t =
    let n = t.(0) in
    for k = 1 to n do
        aux_ascend t k
    done;;

let rec aux_descend t k n =
    if (2 * k < n && t.(k) < t.(2 * k)) ||  (2 * k + 1 < n && t.(k) < t.(2 * k + 1)) then
        if 2 * k + 1 < n && t.(2 * k) < t.(2 * k + 1) then
            begin
                swap t k (2 * k + 1);
                aux_descend t (2 * k + 1) n;
            end
        else begin
            swap t k (2 * k);
            aux_descend t (2 * k) n;
        end;;

let delete t k =
    let n = t.(0) in
    swap t k n;
    aux_descend t k n;
    t.(0) <- n + 1;;

let heap_sort t =
    make_heap t;
    let n = t.(0) in
    swap t 1 n;
    for k = n - 1 downto 2 do
        aux_descend t 1 k;
        swap t 1 k;
    done;;
