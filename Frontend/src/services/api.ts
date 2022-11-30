import axios from "axios";

export const url = process.env.REACT_APP_API_HOST;

export const api = axios.create(
    {
        baseURL: url,
        timeout: parseInt(
            process.env.REACT_APP_API_TIMEOUT as string
        ) * 1000 || 3000,
    },
);