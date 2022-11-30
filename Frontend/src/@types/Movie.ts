type MoovieProperty =
{
    id?: number|string,
    title: string,
    banner: string|number,
    director: string,
    cast: string,
    description: string,
    duration_min: number|string,
    inquiry: number,
}

const MooviePattern: MoovieProperty = {
    id: "",
    title: "",
    banner: "",
    director: "",
    cast: "",
    description: "",
    duration_min: "",
    inquiry: 0,
}

export { type MoovieProperty, MooviePattern };