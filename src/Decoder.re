let author = (json: Js.Json.t): Types.author =>
  Json.Decode.{
    username: json |> field("username", string),
    bio: json |> field("bio", optional(string)),
    image: json |> field("image", string),
    following: json |> field("following", bool),
  };

let article = (json: Js.Json.t): Types.article =>
  Json.Decode.{
    slug: json |> field("slug", string),
    title: json |> field("title", string),
    description:
      (json |> field("description", optional(string)))
      ->(Belt.Option.getWithDefault("")),
    body: json |> field("body", string),
    tagList: json |> field("tagList", array(string)) |> Belt.List.fromArray,
    createdAt: json |> field("createdAt", date),
    updatedAt: json |> field("updatedAt", date),
    favorited: json |> field("favorited", bool),
    favoritesCount: json |> field("favoritesCount", int),
    author: json |> field("author", author),
  };

let profile = (json: Js.Json.t): Types.profile =>
  Json.Decode.{
    username: json |> field("username", string),
    bio: json |> field("bio", optional(string)),
    image: json |> field("image", string),
    following: json |> field("following", bool),
  };

let comment = (json: Js.Json.t): Types.comment =>
  Json.Decode.{
    id: json |> field("id", int),
    createdAt: json |> field("createdAt", date),
    updatedAt: json |> field("updatedAt", date),
    body: json |> field("body", string),
    author: json |> field("author", author),
  };

let user = (json: Js.Json.t): Types.User.t =>
  Json.Decode.{
    email: json |> field("email", string),
    token: json |> field("token", string),
    username: json |> field("username", string),
    bio: json |> field("bio", optional(string)),
    image: json |> field("image", optional(string)),
    id: json |> field("id", int),
    createdAt: json |> field("createdAt", date),
    updatedAt: json |> field("updatedAt", date),
  };
