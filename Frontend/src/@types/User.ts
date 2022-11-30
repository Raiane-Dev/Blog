type UserProperty =
{
    id?: number|string,
    email: string,
    password: string,
    inquiry: number,
}

const UserPattern: UserProperty = {
    id: "",
    email: "",
    password: "",
    inquiry: 0,
}

export { type UserProperty, UserPattern };