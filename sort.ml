let rec print_list = function
[] -> ()
| h::t -> print_int h ; print_string " " ; print_list t;;

let rec insert x l = match l with
| [] -> [x]
| h::t -> if x <= h then x::h::t else h::(insert x t);;

let rec insertion_sort = function
[] -> []
| h::t -> insert h (insertion_sort t);;

let rec min_remaining = function
    [x] -> (x, [])
    | h::t -> let (u, v ) = min_remaining t in
    if h < u then (h, u::v) else (u, h::v);;

let rec selection_sort = function
[] -> []
| l -> let (u, v) = min_remaining l in u::(selection_sort v);;

let rec divide = function
    [] -> [], []
    | a::[] -> [a], []
    | a::b::c -> let u, v = divide c in a::u, b::v

let rec merge l1 l2 = match l1, l2 with
    | [], _ -> l2
    | _, [] -> l1
    | h1::t1, h2::t2 -> if h1 < h2 then h1::(merge t1 l2) else h2::(merge t2 l1);;

let rec merge_sort l = match l with
    | [] -> []
    | a::[] -> l
    | _ -> let u, v = divide l in merge (merge_sort u) (merge_sort v);;

let rec partition l p = match l with
    | [] -> [], []
    | h::t -> let u, v = partition t p in
    if h < p then h::u, v else u, h::v;;

let rec quick_sort l = match l with
    | [] -> []
    | h::t -> let u, v = partition t h in (quick_sort u)@[h]@(quick_sort v);;

let l = [5; 4; 3; 2; 1];;
print_list (insertion_sort l);;
print_endline " ";;
print_list (selection_sort l);;
print_endline " ";;
print_list (merge_sort l);;
print_endline " ";;
print_list (quick_sort l);;
print_endline " ";;
