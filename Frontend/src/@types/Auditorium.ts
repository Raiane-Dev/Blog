type AuditoriumProperty =
{
    id?: number|string,
    name: string,
    seats_no: string|number,
    inquiry: number,
}

const AuditoriumPattern: AuditoriumProperty = {
    id: "",
    name: "",
    seats_no: "",
    inquiry: 0,
}

export { type AuditoriumProperty, AuditoriumPattern };